#include <iostream>
#include <fstream>
#include <vector>
#include <tuple>

using namespace std;

vector<string> split (string s , string t)
{
    vector<string> parts;
    string c;
    int l,p;
    l = t.length();
    for (int i=0 ; i<s.length() ; i++)
    {
        if (s.substr(i , l) == t)
        {
            parts.push_back(c);
            c = "";
            i += l-1;
        }
        else
        {
            c += s[i];
        }
    }
    parts.push_back(c);

    return parts;
}


tuple<double,double> coef(vector<double> x, vector<double> y) {
    double sum = 0;
    double xp,yp,n,m;
    xp = 0;
    yp = 0;
    n = 0;
    m = 0;

    for (int i = 0; i < x.size(); i++) {
        xp += x[i];
        yp += y[i];
    }
    xp /= x.size();
    yp /= y.size();

    for (int i = 0; i < x.size(); i++) {
        n += (x[i] - xp) * (y[i] - yp);
        m += (x[i] - xp) * (x[i] - xp);
    }

    double a = n/m;
    double b = yp - a * xp;

    return tuple<double,double>(a,b);
}

int main() {
    vector<double> x, y;
    string line;
    ifstream f("data.txt");


    while (getline(f, line)) {
        if (line.empty()) continue;
        vector<string> parts = split(line, " ");
        if (parts.size() == 2) {
            x.push_back(stod(parts[0]));
            y.push_back(stod(parts[1]));
        }
    }


    auto [a,b] = coef(x, y);

    cout << "Coefficient: " << a << endl;
    cout << "Intercept: " << b << endl;
    return 0;
}