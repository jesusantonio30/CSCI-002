#include <iostream>
#include <cmath>
#include <iomanip>
#include <fstream>

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
            printSchedule(ostream& out, bool csv);
};

int main() {

    double loanAmt = 0;
    int term = 0;
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

    calcLoan.printSchedule(cout, false);


    ofstream csvSchedule("amortization_schedule.csv");

    if (!csvSchedule) {
        cerr << "Error opening file for writing." << endl;
        return 1;
    }
    
    calcLoan.printSchedule(csvSchedule, true);
    csvSchedule.close();
    
    

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

void Loan::printSchedule(ostream& out, bool csv) {
    out << fixed << setprecision(2);

    if (csv) {
        out << "Month,Payment,Principal,Interest,Balance\n";
    } else {
        out << "Initial Balance: " << initialLoanAmt << endl;
    }

    balance = initialLoanAmt;
    for (int i = 1; i <= term; i++) {
        double interest = calcInterest();
        double principal = fixedPayment - interest;
        balance = balance - principal;

        if (csv) {
            out << i << ","
                << fixedPayment << ","
                << principal << ","
                << interest << ","
                << balance << "\n";
        } else {
            out << "----------- Month " << i << "  -----------\n";
            out << "Payment: " << fixedPayment << endl;
            out << "Principal: " << principal << endl;
            out << "Interest: " << interest << endl;
            out << "Balance: " << balance << endl;
        }
    }
}