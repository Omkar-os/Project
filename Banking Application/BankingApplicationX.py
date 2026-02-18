# ------------------------------------
# Banking Application with Fixed Login
# ------------------------------------

import os


class BankAccount:

    def __init__(self, username):
        self.username = username
        self.balance = 0
        self.transactions = []
        self.filename = username + ".txt"
        self.load_data()


    # ----------------------------
    # Load old data if file exists
    # ----------------------------
    def load_data(self):

        if os.path.exists(self.filename):

            file = open(self.filename, "r")
            lines = file.readlines()

            if len(lines) > 0:
                self.balance = float(lines[0].strip())

                for line in lines[1:]:
                    self.transactions.append(line.strip())

            file.close()


    # ----------------------------
    # Save data into file
    # ----------------------------
    def save_data(self):

        file = open(self.filename, "w")

        file.write(str(self.balance) + "\n")

        for t in self.transactions:
            file.write(t + "\n")

        file.close()


    # ----------------------------
    # Deposit Function
    # ----------------------------
    def deposit(self):

        try:
            amount = float(input("Enter amount to deposit: ₹"))

            if amount > 0:
                self.balance = self.balance + amount
                self.transactions.append("Deposited ₹" + str(amount))
                print("Money deposited successfully!")
            else:
                print("Amount must be greater than 0")

        except:
            print("Please enter valid number.")


    # ----------------------------
    # Withdraw Function
    # ----------------------------
    def withdraw(self):

        try:
            amount = float(input("Enter amount to withdraw: ₹"))

            if amount <= 0:
                print("Amount must be greater than 0")

            elif amount > self.balance:
                print("Insufficient balance!")

            else:
                self.balance = self.balance - amount
                self.transactions.append("Withdrawn ₹" + str(amount))
                print("Money withdrawn successfully!")

        except:
            print("Please enter valid number.")


    # ----------------------------
    # Check Balance
    # ----------------------------
    def check_balance(self):
        print("Your current balance is: ₹", self.balance)


    # ----------------------------
    # Show Transactions
    # ----------------------------
    def show_transactions(self):

        print("\n---- Transaction History ----")

        if len(self.transactions) == 0:
            print("No transactions yet.")

        else:
            for t in self.transactions:
                print(t)


# ------------------------------------
# Main Program
# ------------------------------------

def main():

    print("\n====== Welcome to Secure Banking System ======\n")

    # Fixed Credentials
    correct_username = "OMKAR"
    correct_pin = 1702

    username = input("Enter Username: ")

    try:
        pin = int(input("Enter PIN: "))
    except:
        print("PIN must be a number!")
        return

    # Login Verification
    if username != correct_username or pin != correct_pin:
        print("Invalid Username or PIN. Access Denied.")
        return

    print("Login Successful!\n")

    # Create account object
    account = BankAccount(username)

    # Menu Loop
    while True:

        print("""
1. Deposit Money
2. Withdraw Money
3. Check Balance
4. Show Transaction History
5. Exit
""")

        try:
            choice = int(input("Enter your choice: "))
        except:
            print("Please enter valid number.")
            continue

        if choice == 1:
            account.deposit()

        elif choice == 2:
            account.withdraw()

        elif choice == 3:
            account.check_balance()

        elif choice == 4:
            account.show_transactions()

        elif choice == 5:
            account.save_data()
            print("Thank you for using Banking System.")
            break

        else:
            print("Invalid choice. Please select 1 to 5.")


# Run Program
main()
