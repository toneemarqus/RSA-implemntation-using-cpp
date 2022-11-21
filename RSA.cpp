#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>

using namespace std;

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
int relativelyprime(int n) // finding e
{
    int num;
    int i;
    for (i = 2; i < n; i++)
    {
        num = gcd(i, n);
        if (num == 1)
            break;
    }
    return i;
}

int keycal(int e, int np) // calculating d
{
    int num, i;
    for (i = 2; i < np; i++)
    {
        num = (i * e) % np;
        if (num == 1)
            break;
    }
    return i;
}

int SquareandMultiply(int m, int d, int mod) // (a x b) mod n = [(m mod n) x (d mod n)] mod n

{

    int result = 1;
    while (d > 0)
    {
        if (d & 1) // if the last bit of the binary of d is 1
        {
            result = (result * m) % mod;
        }
        m = (m * m) % mod; // making m^2, m^4, m^8 ... etc
        d = d >> 1;        // shifting the bits to the right for eg 0101 => 0010 then 0001
    }
    return result;
}

int main()
{
    int n, np, p, q, e, d, m, c;
    int choice, choice2 = 0;
    vector<int> v{2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
    srand(unsigned(time(NULL)));
    cout << "Please make a choice: " << endl;
    cout << " 1 for Auto values" << endl;
    cout << " 2 for Manual values " << endl;
    cin >> choice2;
    if (choice2 == 1)
    {
        random_shuffle(v.begin(), v.end()); // shuffling the vector for randomisation
        p = v[1];                           // taking first value because we already shuffled the vector so it doesnt matter which value we take
        do
        {
            random_shuffle(v.begin(), v.end());
            q = v[12];
        } while (p == q); // making sure p != q

        n = q * p;              // finding n
        np = (q - 1) * (p - 1); // finding np
        e = relativelyprime(np);
        d = keycal(e, np);
        
    }
    else
    {
        cout << "Please input p:" << endl;
        cout << "Allow values 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97" << endl;
        cin >> p;
        cout << "Please input q:" << endl;
        cout << "Allow values 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97" << endl;

        cin >> q;
        n = q * p;
        np = (q - 1) * (p - 1);
    }

    do
    {
        cout << "Please make a choice: " << endl;
        cout << " 1 for Encryption" << endl;
        cout << " 2 for Decryption " << endl;
        cout << " 3 to exit the program" << endl;
        cin >> choice;
        if (choice == 1 && choice2 == 1)
        {
            cout << "Please input M" << endl;
            cin >> m;
            c = SquareandMultiply(m, e, n);
            cout << "p " << p << "| q  " << q << "| n " << n << " | np " << np << "| e " << e << "| d " << d << " |C " << c << "\n\n\n\n";
        }
        else if (choice == 2 && choice2 == 1)
        {

            cout << "Please input C" << endl;
            cin >> c;
            m = SquareandMultiply(c, d, n);
            cout << "p " << p << "| q  " << q << "| n " << n << " | np " << np << "| e " << e << "| d " << d << " |M " << m << "\n\n\n\n";
        }
        else if (choice == 1 && choice2 == 2)
        {
          
            cout << "Please input e:" << endl;
            cin >> e;
            d = keycal(e, np);
            cout << "Please input M" << endl;
            cin >> m;
            c = SquareandMultiply(m, e, n);
            cout << "p " << p << "| q  " << q << "| n " << n << " | np " << np << "| e " << e << "| d " << d << " |C " << c << "\n\n\n\n";
        }
        else if (choice == 2 && choice2 == 2)
        {
            cout << "Please input d:" << endl;
            cin >> d;
            cout << "Please input C" << endl;
            cin >> c;
            m = SquareandMultiply(c, d, n);
            cout << "p " << p << "| q  " << q << "| n " << n << " | np " << np << "| e " << e << "| d " << d << " |M " << m << "\n\n\n\n";
        }
    } while (choice != 3);

    cout << "\n Bye Bye :) \n\n\n\n";
}