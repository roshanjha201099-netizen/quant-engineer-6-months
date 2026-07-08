import random

def toss_coin() -> int:
    tosses = 0
    while True:
        tosses += 1
        if random.random() < 0.5:
            return tosses

def simulate(trials: int) -> float:
    total_tosses = 0
    for _ in range(trials):
        total_tosses += toss_coin()
    return total_tosses / trials

if __name__ == "__main__":
    trials = 100_000

    simulated_expected_tosses = simulate(trials)
    theoretical_expected_tosses = 2.0

    print(f"Trials: {trials}")
    print(f"Simulated expected tosses: {simulated_expected_tosses}")
    print(f"Theoretical expected tosses: {theoretical_expected_tosses}")
    print(f"Difference: {abs(simulated_expected_tosses - theoretical_expected_tosses)}")