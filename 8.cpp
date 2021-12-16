#include <iostream>
#include <iomanip>

using namespace std;
char s[255] = "adadad\n";

ostream& endp(ostream& out, int n, string s) {

    char ss[255];
    static int k = 0;
    int i, j, c = n;
    for (i = 0, j = 0; s[j] != '\0'; i++, j++)
    {
        ss[i] = s[j];
        if (ss[i] == '\n')
        {
            k++;
            if (k == c)
            {
                ss[i + 1] = '\n';
                out << "\n-------------\n";
                i = -1;
            }
        }
    }
    if (i < 0)
    {
        ss[i + 1] = '\0';
        out << ss;
    }
    out << s;
    return out;
}

ostream& endp(ostream& out, int n) {

    char ss[255];
    static int k = 0;
    int i, j, c = n;
    for (i = 0, j = 0; s[j] != '\0'; i++, j++)
    {
        ss[i] = s[j];
        if (ss[i] == '\n')
        {
            k++;
            if (k == c)
            {
                ss[i + 1] = '\n';
                out << "\n-------------\n";
                i = -1;
            }
        }
    }
    if (i < 0)
    {
        ss[i + 1] = '\0';
        out << ss;
    }
    return out;
}

ostream& endp(ostream& out) {

    char ss[255];
    static int k = 0;
    int i, j, c = 5;
    for (i = 0, j = 0; s[j] != '\0'; i++, j++)
    {
        ss[i] = s[j];
        if (ss[i] == '\n')
        {
            k++;
            if (k == c)
            {
                ss[i + 1] = '\n';
                out << "\n-------------\n";
                i = -1;
            }
        }
    }
    if (i < 0)
    {
        ss[i + 1] = '\0';
        out << ss;
    }
    return out;
}


int main() {

	float f = 12.39481;
	cout << f << endl;
    string s = "this is A tesT sTrInG";

	cout << scientific << f << endl;
	cout <<setw(30)<< setfill('-') << right <<  fixed << f << endl;
	cout <<setw(30)<< setfill('-') << left << f << endl;

	cout << fixed << "2 \n";
	int a = 28;
	cout << hex << a << endl;
	cout << oct << a << endl;
	cout << dec << a << endl;
	cout.setf(ios::showpos);
	cout << a << endl;
	cout.unsetf(ios::showpos);

    cout << endl << endl << setfill('*') << setw(50) << "ex4" << endl;
    for (int i = 0; i < 7; i++)
        cout << s << endp;


	return 0;
}
