import random 

def dice_exp_val(trails:int)->float:
    total_val=0

    for _ in range(trails):
        dice=random.randint(1,6)
        total_val+=dice


    return total_val/trails


if __name__=="__main__":
    trails=int(input("Enter the number of trails: "))
    theratical_exp_val=3.5  
    print(f"Theoretical expected value of dice is: {theratical_exp_val}")
    print(f"Expected value of dice after {trails} trails is: {dice_exp_val(trails)}")
    print(f"diff b/w theory and simulation is: {abs(theratical_exp_val-dice_exp_val(trails))}")