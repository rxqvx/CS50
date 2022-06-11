import cs50

# print("Change owed: ");
# cents = float(input(""))

cents = cs50.get_float("Change owed: ")
while True:
    if cents>0:
        break
    else:
        cents = cs50.get_float("Change owed: ")

cents=round(cents*100)
def calculateQuarter(cents):
    if(cents>=0.25):

        quarters=cents/25

    else:
        quarters=0
    return int(quarters)

def calculateDimes(cents):
    if(cents>=0.10):
        dimes=(cents%25)/10
    else:
        dimes=0
    return int(dimes)

def calculateNickels(cents):
    if(cents>=0.05 ):
        nickels=((cents%25)%10)/5
    else:
        nickels=0
    return int(nickels)

def calculatePennies(cents):
    if(cents>=0.01):
        pennies=(((cents%25)%10)%5)/1
    else:
        pennies=0
    return int(pennies)

quarters=0
dimes=0;
nickels=0
pennies=0

quarters = (calculateQuarter(cents))
# print("quarters={}".format(quarters))
cents = cents - quarters * 25;

dimes = (calculateDimes(cents))
# print("dimes={}".format(dimes))
cents = cents - dimes * 10;

nickels = (calculateNickels(cents))
#print("nickels={}".format(nickels))
cents = cents - nickels * 5;

pennies=(calculatePennies(cents))
#print("pennies={}".format(pennies))
cents = cents - pennies * 1;

coins = quarters + dimes + nickels + pennies
moedas=int(coins)
print("{}\n".format(moedas))