#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

class Loan {
    private:
        double 
            initialLoanAmt,
            rate,
            balance,
            fixedPayment;
        int term;

    public:

        Loan(double initLoanAmt, double apr, int term);

        double calcInterest();
            
        void 
            calcMonthlyPayment(),
            printSchedule();
};

int main() {

    double loanAmt = 0;
    double term = 0;
    double apr = 0;

    cout << "==================================\n";
    cout << "   Loan Amortization Calculator\n";
    cout << "==================================\n";

    cout << "\n\nAmount to Finance: ";
    cin >> loanAmt;

    cout << "\nLoan Term in years: ";
    cin >> term;

    cout << "\nAnnual Percentage Rate (APR %): ";
    cin >> apr;

    Loan calcLoan(loanAmt, apr, term);

    calcLoan.printSchedule();
    
    

    return 0;
}

Loan::Loan(double initLoanAmt, double apr, int term) {
    this->initialLoanAmt = initLoanAmt;
    this->rate = (apr / 100) / 12.0;
    this->term = term * 12;

    calcMonthlyPayment();
}

void Loan::calcMonthlyPayment() {
    fixedPayment = initialLoanAmt * (rate * (pow(1 + rate, term)) / ((pow(1 + rate, term) - 1)));
}

double Loan::calcInterest() {
    return balance * rate;
}

void Loan::printSchedule() {
    cout << fixed << setprecision(2);
    
    cout << "Initial Balance: " << initialLoanAmt << endl;
    balance = initialLoanAmt;

    for (int i = 1; i <= term; i++) {
        double interest = calcInterest();
        double principal = fixedPayment - interest;
        balance = balance - principal;

        cout << "----------- Month " << i << "  -----------\n";
        cout << "Payment: " << fixedPayment << endl;
        cout << "Principal: " << principal << endl;
        cout << "Interest: " << interest << endl;
        cout << "Balance: " << balance << endl;
    }
}