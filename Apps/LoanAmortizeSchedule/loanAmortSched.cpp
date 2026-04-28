#include <iostream>
#include <cmath>

using namespace std;

class Loan {
    private:
        float 
            initialLoanAmt,
            apr,
            balance,
            fixedPayment;
        int term;

    public:

        Loan(float initLoanAmt, float apr, int term);

        float calcInterest();
            
        void 
            calcMonthlyPayment(),
            printSchedule();
};

int main() {

    return 0;
}

Loan::Loan(float initLoanAmt, float apr, int term) {
    this->initialLoanAmt = initLoanAmt;
    this->apr = apr;
    this->term = term;

    calcMonthlyPayment();
}

void Loan::calcMonthlyPayment() {
    float rate = apr / 12;
    fixedPayment = initialLoanAmt * ((rate * pow(1 + rate, term)) / (pow(1 + rate, term) - 1));
}

float Loan::calcInterest() {
    float rate = apr / 12;
    return balance * rate;
}

void Loan::printSchedule() {
    cout << "Initial Balance: " << initialLoanAmt << endl;
    balance = initialLoanAmt;

    for (int i = 1; i <= term; i++) {
        float interest = calcInterest();
        float principal = fixedPayment - interest;
        balance -= principal;

        cout << "----------- Month " << i << "  -----------\n";
        cout << "Payment: " << fixedPayment << endl;
        cout << "Principal: " << principal << endl;
        cout << "Interest: " << interest << endl;
        cout << "Balance: " << balance << endl;
    }
}