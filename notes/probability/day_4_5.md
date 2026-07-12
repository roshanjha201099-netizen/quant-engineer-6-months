# Quant Engineer Prep - Probability & Statistics

# Day 4 + Day 5 Notes

---

# ✅ Day 4

## 1. Probability Density Function (PDF)

### Why do we need PDF?

PMF works only for **Discrete Random Variables**.

For Continuous Random Variables,

there are infinitely many possible values.

Example

- Height
- Weight
- Temperature
- Time

For continuous variables,

\[
P(X=x)=0
\]

because a single point has zero width.

Hence PMF cannot be used.

So we introduce **PDF (Probability Density Function).**

---

## PDF Meaning

PDF gives **Density**, NOT Probability.

Probability is obtained using

> **Area under the PDF curve.**

---

## Important Rule

\[
\boxed{\text{Probability = Area under PDF}}
\]

NOT

Height.

---

## Uniform Distribution

Notation

\[
X\sim Uniform(a,b)
\]

Read as

> X follows a Uniform Distribution from **a** to **b**.

---

### Height of Uniform Distribution

Since total probability must be 1,

Area of rectangle = 1

Area

\[
=\text{Height}\times(b-a)
\]

Therefore

\[
\boxed{\text{Height}=\frac1{b-a}}
\]

---

### Examples

#### Example 1

\[
X\sim Uniform(0,1)
\]

Height

\[
=1
\]

---

#### Example 2

\[
X\sim Uniform(2,8)
\]

Width

\[
8-2=6
\]

Height

\[
=\frac16
\]

---

## Probability using PDF

Example

\[
X\sim Uniform(0,1)
\]

Find

\[
P(0.2\le X\le0.6)
\]

Area

Height

\[
1
\]

Width

\[
0.6-0.2=0.4
\]

Probability

\[
1\times0.4=0.4
\]

---

## Exact Probability

Very Important

For Continuous Random Variables

\[
\boxed{P(X=x)=0}
\]

Reason

A single point has zero area.

---

# 2. Cumulative Distribution Function (CDF)

Full Form

**Cumulative Distribution Function**

Meaning

Running Total Probability.

Formula

\[
\boxed{F(x)=P(X\le x)}
\]

Read

Probability that X is less than or equal to x.

---

## Intuition

### Discrete

PMF

↓

Add probabilities

↓

CDF

Think of it as **Prefix Sum**.

---

### Continuous

PDF

↓

Area till x

↓

CDF

---

## Uniform Distribution Example

\[
X\sim Uniform(0,1)
\]

Find

\[
F(0.4)
\]

Area

Height

1

Width

0.4

Answer

0.4

---

## Properties of CDF

- Starts from 0
- Ends at 1
- Never decreases
- Running total probability

---

## Difference

### PMF

Exact Probability

Used for Discrete Random Variables.

---

### PDF

Density

Used for Continuous Random Variables.

Probability = Area.

---

### CDF

Running Total Probability.

---

# Day 4 Summary

Completed

- PDF
- Uniform Distribution
- Exact Probability
- Area under PDF
- CDF
- Relationship between PMF, PDF and CDF

---

# ✅ Day 5

# Bernoulli Distribution

---

## Motivation

Many experiments have only two outcomes.

Examples

- Pass / Fail
- Success / Failure
- Spam / Not Spam
- Light Works / Doesn't Work
- Selected / Rejected

Such experiments are called **Bernoulli Trials**.

---

## Bernoulli Trial

Exactly

- One Trial
- Two Outcomes

Success Probability

\[
p
\]

Failure Probability

\[
q=1-p
\]

---

## Random Variable

Define

Success

\[
X=1
\]

Failure

\[
X=0
\]

Possible values

\[
\boxed{X\in\{0,1\}}
\]

Notation

\[
\boxed{X\sim Bernoulli(p)}
\]

---

## PMF

| X | P(X) |
|---|------|
|0|1-p|
|1|p|

---

## Examples

- Did a die show 6?
- Student Passed?
- Login Successful?
- Email Spam?

---

# Binomial Distribution

---

## Motivation

Suppose

A coin is tossed 5 times.

Question

How many Heads occurred?

Now we are counting

**Number of Successes.**

---

## Definition

A Binomial Distribution is

> Repeated Bernoulli Trials.

---

## Random Variable

\[
X=\text{Number of Successes}
\]

Possible values

\[
0,1,2,\ldots,n
\]

Notation

\[
\boxed{X\sim Binomial(n,p)}
\]

where

n

Number of Trials

p

Success Probability

---

## PMF Intuition

Suppose

Exactly r successes are needed.

One arrangement

Probability

\[
p^rq^{n-r}
\]

But there are many possible arrangements.

Number of arrangements

\[
{n\choose r}
\]

Therefore

\[
\boxed{
P(X=r)
=
{n\choose r}
p^r
q^{n-r}
}
\]

---

## Important Intuition

Binomial asks

> **How many successes happened?**

---

## Examples

- Heads in 10 tosses
- Students selected
- Defective products
- Successful trades

---

# Geometric Distribution

---

## Motivation

Question changes.

Instead of

How many successes?

We ask

When does the **first success** occur?

---

## Random Variable

\[
X=
\text{Trial number of first success}
\]

Possible values

\[
1,2,3,\ldots
\]

Notice

0 is impossible.

---

## PMF Intuition

To get first success on nth trial

First

n−1 trials must fail.

Last trial must succeed.

Probability

\[
q^{n-1}p
\]

Therefore

\[
\boxed{
P(X=n)
=
q^{n-1}p
}
\]

---

## Expected Value

Average number of trials before first success

\[
\boxed{
E(X)=\frac1p
}
\]

Examples

Coin

\[
p=\frac12
\]

Expected Tosses

2

---

Dice

\[
p=\frac16
\]

Expected Rolls

6

---

## Important Intuition

Geometric asks

> **When will the first success happen?**

---

# Comparison

| Distribution | Meaning | Random Variable |
|--------------|---------|----------------|
| Bernoulli | One Trial | Success / Failure (0 or 1) |
| Binomial | n Trials | Number of Successes |
| Geometric | Repeat until Success | Trial number of First Success |

---

# Final Mental Map

```
Random Variable
       │
       ▼
Bernoulli
(One Trial)
       │
       ├──────────────► Binomial
       │               (n Trials)
       │               Count Successes
       │
       └──────────────► Geometric
                       Repeat Until
                       First Success
```

---

# Topics Completed So Far

## Probability Basics

- ✅ Probability
- ✅ Complement Rule
- ✅ Conditional Probability

---

## Expectation & Variance

- ✅ Expected Value
- ✅ Variance
- ✅ Expected Attempts

---

## Random Variables

- ✅ Random Variables
- ✅ Discrete RV
- ✅ Continuous RV

---

## Functions

- ✅ PMF
- ✅ PDF
- ✅ CDF

---

## Continuous Distributions

- ✅ Uniform Distribution

---

## Discrete Distributions

- ✅ Bernoulli
- ✅ Binomial
- ✅ Geometric

---

# Next Topics

- Independence
- Mutually Exclusive Events
- Law of Total Probability
- Bayes Theorem
- Poisson Distribution
- Exponential Distribution
- Normal Distribution
- Covariance
- Correlation
- Central Limit Theorem