# Quant Engineer Prep - Probability & Statistics Progress

---

# ✅ Day 1

## 1. Probability Basics

### Learned

- What is Probability
- Sample Space
- Events
- Probability Formula

P(E) = Favourable Outcomes / Total Outcomes

### Rules

- 0 ≤ P(E) ≤ 1
- Impossible Event
- Certain Event
- Complement Rule

---

## 2. Expected Value (Expectation)

Learned

- Long run average
- Expected Value intuition
- Dice Example
- Coin Example
- Expected Earnings
- Expected Attempts till First Success

Formula

E(X) = Σ xP(x)

Concepts

- Expected value is NOT always a possible outcome.
- It represents the average over many trials.

---

## 3. Variance

Learned

- Why variance exists
- Why spread matters
- Small vs Large Variance
- Intuition

Formula

Var(X) = E(X²) - (E(X))²

Learned

- How to calculate variance
- Why we square deviations

---

## 4. Conditional Probability

Learned

Meaning of "Given"

Golden Rule

Whenever "Given" appears,

Sample Space changes.

Formula

P(A|B)=P(A∩B)/P(B)

Examples

- Cards
- Dice
- Students

---

## 5. Geometric Distribution (Introduction)

Learned

Expected Attempts till First Success

E = 1/p

Probability of First Success on nth Trial

(1-p)^(n-1) × p

---

## 6. Python Simulation

Done

- Coin Toss Simulation
- Expected Value Simulation
- Large Number Intuition

---

# ✅ Day 2

## Random Variables

Learned

- Random Variable is NOT a random number.
- It is a function that maps outcomes to numbers.

Examples

Dice

Coin

Odd/Even Mapping

---

## Discrete Random Variables

Learned

Countable Values

Examples

- Dice
- Coin
- Number of Customers
- Emails

---

## Continuous Random Variables

Learned

Infinite Possible Values

Examples

- Height
- Weight
- Time
- Distance
- Temperature

Important

Cannot list all possible values.

---

## PMF (Probability Mass Function)

Used For

Discrete Random Variables

Meaning

Probability of Exact Value

Properties

- Sum of all probabilities = 1
- Probability between 0 and 1

Examples

- Coin
- Dice

Learned

PMF is built on Random Variable values,
not directly on sample space.

---

## Why PMF Fails

Continuous Variables

Learned

P(X = exact value) = 0

Hence PMF cannot represent continuous variables.

---

# ✅ Day 3

## PDF (Probability Density Function)

Learned

- Why PDF was invented
- Density vs Probability
- Exact probability is NOT given by PDF
- Probability = Area under PDF

Important

PDF gives Density,
NOT Probability.

---

## Uniform Distribution

Learned

Notation

X ~ Uniform(a,b)

Read as

"X follows a Uniform Distribution between a and b."

Height

1/(b-a)

Derived using Area = 1

Solved

Uniform(0,1)

Uniform(2,8)

Uniform(3,7)

Range Probability Questions

---

## CDF (Cumulative Distribution Function)

Meaning

Running Total Probability

Formula

F(x)=P(X≤x)

Discrete

CDF = Prefix Sum of PMF

Continuous

CDF = Area under PDF till x

Properties

- Starts from 0
- Ends at 1
- Never decreases

Solved

Uniform Distribution CDF Questions

---

# 🔥 Core Intuitions Built

✅ Random Variable is a function.

✅ PMF gives exact probability.

✅ PMF works only for Discrete variables.

✅ Continuous variables have infinitely many values.

✅ P(X = exact value) = 0 for Continuous Variables.

✅ PDF gives Density, not Probability.

✅ Probability = Area under PDF.

✅ CDF = Running Total Probability.

---

# ✅ Python Work

Completed

- Coin Toss Simulation
- Expected Value Simulation
- Probability Verification

---

# 📚 Topics Completed

Probability

- [x] Probability Basics
- [x] Complement Rule
- [x] Expected Value
- [x] Variance
- [x] Conditional Probability
- [x] Random Variables
- [x] Discrete RV
- [x] Continuous RV
- [x] PMF
- [x] PDF
- [x] Uniform Distribution
- [x] CDF
- Bernoulli Distribution
- Binomial Distribution
- Geometric Distribution (Formal)


---

# 🚀 Next Topics
- Poisson Distribution
- Normal Distribution
- Bayes Theorem
- Law of Total Probability
- Independence
- Covariance
- Correlation