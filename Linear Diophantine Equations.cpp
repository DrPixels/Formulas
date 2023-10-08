#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int x = 0;
    int y = 0;
    int c = 0; //constant value
    int m, n; // m larger, n smaller
    int b,a; //value for the general solution
    int q, r = 0; // quotient and remainder
    int prevRemainder = 0;
    int greatestCD = 0;
    
    //For Bezout
    int xprime = 0;
    int yprime = 0;
    int prevXprime = 0;
    int prevYprime = 0;
    
    //For x-naught & y-naught
    int k = 0;
    int x_naught = 0;
    int y_naught = 0;
    
    
    bool hasSolution;
    
    vector<int> mResult;
    vector<int> nResult;
    vector<int> qResult;
    vector<int> rResult;
    vector<int> bezoutX;
    vector<int> bezoutY;

    
    cout<<"SOLVING LINEAR DIOPHANTINE EQUATIONS" << endl << endl;
    cout<<"Enter the value of x: ";
    cin >> x;
    cout << "Enter the value of y: ";
    cin >> y;
    cout << "Enter the value of constant: ";
    cin >> c;
    cout << endl;
    
    cout << "Equation: " << x <<"x + " << y <<"y = "<< c << endl << endl;
    if (x < y) {
        cout<< "Since the value of x is less than y" << endl;
        cout << "New Equation: " << y <<"x + " << x <<"y = "<< c << endl << endl;
    }
    
    m = max(x, y);
    n = min(x, y);
    
    b = n;
    a = m;
    do {
        mResult.push_back(m);
        nResult.push_back(n);
        
        prevRemainder = r;
        q = m / n; 
        r = m % n;
        
        qResult.push_back(q);
        rResult.push_back(r);
        
        if (r == 0) {
            greatestCD = prevRemainder;
            break;
        }
        
        m = n;
        n = r;
        
    } while (r != 0);
    
    //To check if the LDE has solution
    if (c % greatestCD == 0) {
        cout << "The GCD divides the constant. The LDE has solution."<< endl;
        hasSolution = true;
    }
    else {
        cout << "The GCD do not divide the constant. The LDE has no solution." << endl;
        hasSolution = false;
    }
    
    if (hasSolution == true) {
            //For Bezout's Coefficient
    
    int bezoutLoop = mResult.size() - 2;
    
    for (; bezoutLoop >=0 ; bezoutLoop--) {
        
        if (bezoutLoop == mResult.size() - 2) {
            xprime = 1;
            yprime = (-1)*(qResult[bezoutLoop]);
            prevXprime = xprime;
            prevYprime = yprime;
            
            bezoutX.insert(bezoutX.begin(), xprime);
            bezoutY.insert(bezoutY.begin(), yprime);
        }
        else {
            xprime = prevYprime;
            yprime = prevXprime - (prevYprime*qResult[bezoutLoop]);
            prevXprime = xprime;
            prevYprime = yprime;
            
            bezoutX.insert(bezoutX.begin(), xprime);
            bezoutY.insert(bezoutY.begin(), yprime);
        }
    }
    
    
    for (int i = 0; i < mResult.size() ; i++) {
        if (i == 0) {
            cout << "m\t" << "n\t" << "q\t" << "r\t" << "x'\t" << "y'" <<  endl;
        }
        
        if(i == mResult.size() - 1) {
            cout << mResult[i] << "\t" << nResult[i] << "\t" << qResult[i] << "\t" << rResult[i] << "\t"<<  "-" << "\t" << "-" << endl;
        }
        
        else {
            cout << mResult[i] << "\t" << nResult[i] << "\t" << qResult[i] << "\t" << rResult[i] << "\t"<<  bezoutX[i] << "\t" << bezoutY[i] << endl;
        }
        
    }
    
    cout << endl << "GCD: " << greatestCD << endl;
    cout << "x' = " << bezoutX[0] << " & y' = " << bezoutY[0];
    
    //Compute x0, y0
    k = c/greatestCD;
    x_naught = xprime * k;
    y_naught = yprime * k;
    
    cout << endl << "Value of k: " << k << endl;
    cout << "Value of [X0] xnaught = " << x_naught << endl;
    cout << "Value of [Y0] ynaught = " << y_naught << endl << endl << endl;
    
    cout << "General Solution" << endl;
    cout << "X = " << x_naught << " + " << (b/greatestCD) << "t" << endl;
    cout << "Y = " << y_naught << " - " << (a/greatestCD) << "t";
    }
    
    return 0;
}
