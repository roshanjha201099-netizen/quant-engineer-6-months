import random

def simulate_coin_tosses(trails:int,tosses_per_trail:int)->float:
    total_heads=0

    for _ in range(trails):
        heads=0
        for _ in range(tosses_per_trail):
            if random.random()<0.5:
                heads+=1
        total_heads+=heads
    return total_heads/(trails)

if __name__=="__main__":
    trails=1000
    tosses_per_trail=10
    average_heads=simulate_coin_tosses(trails,tosses_per_trail)
    print(f"Average number of heads in {tosses_per_trail} tosses over {trails} trials: {average_heads}")
    print(f"Expected number of heads: {tosses_per_trail/2}")


# Average number of heads in 10 tosses over 1000 trials: 4.972
# Expected number of heads: 5.0