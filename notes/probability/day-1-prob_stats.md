# Probability & Statistics - Day 1

---

# 1. Probability Basics

## Definition

Probability = Chance of an event happening.

## Formula

P(E) = Favourable Outcomes / Total Outcomes

Example:

Dice

Probability of getting an even number

Favourable = {2,4,6} = 3

Total = 6

Answer = 3/6 = 1/2

---

## Rules

0 ≤ P(E) ≤ 1

Impossible Event = 0

Certain Event = 1

---

## Complement Rule

P(Not A)

= 1 - P(A)

Example

P(Not getting 6)

= 1 - 1/6

= 5/6

---

# 2. Expected Value

## Meaning

Expected Value = Long Run Average

Formula

E(X) = Σ xP(x)

where

x = value

P(x) = probability of value

---

## Example

| X | P(X) |
|---|------|
|2|0.2|
|4|0.5|
|6|0.3|

E(X)

= 2(0.2)+4(0.5)+6(0.3)

= 0.4+2+1.8

= 4.2

---

## Dice Example

E(X)

= (1+2+3+4+5+6)/6

= 3.5

Note:

Expected Value doesn't have to be an actual outcome.

Dice never gives 3.5.

It is just the average after many trials.

---

## Expected Earning Example

Win ₹100 with probability 0.2

Lose ₹20 with probability 0.8

Expected earning

= 100(0.2)+(-20)(0.8)

=20−16

= ₹4

Remember:

Loss is always negative.

---

## Expected Attempts till First Success

If success probability = p

Expected Attempts

E = 1/p

Examples

Coin

p=1/2

Answer = 2

Dice (first 6)

p=1/6

Answer = 6

---

# 3. Variance

## Meaning

Variance tells us

"How spread out the data is from its average."

Small Variance

→ Values are close to Mean

Large Variance

→ Values are far from Mean

---

## Formula

Var(X)

= E(X²) − (E(X))²

---

## Steps

Step 1

Find E(X)

Step 2

Find E(X²)

(Remember to square x first.)

Step 3

Variance

= E(X²) − (E(X))²

---

## Example

| X | P(X) |
|---|------|
|1|0.5|
|3|0.5|

Step 1

E(X)

=1(0.5)+3(0.5)

=2

Step 2

E(X²)

=1²(0.5)+3²(0.5)

=0.5+4.5

=5

Step 3

Variance

=5−2²

=1

---

## Intuition

Student A

50 50 50 50 50

Variance = 0

Student B

0 100 0 100 50

Variance is High

Reason:

Average may be same,

but values are much more spread out.

---

# 4. Conditional Probability

## Meaning

Probability of A

GIVEN

B has already happened.

Notation

P(A | B)

---

## Golden Rule ⭐⭐⭐⭐⭐

Whenever you see

"GIVEN"

The sample space changes.

The thing after "Given"

becomes the NEW sample space.

---

## Formula

P(A|B)

= P(A ∩ B) / P(B)

---

## Example 1

Deck of Cards

Given card is Red

Probability card is Heart

Total Red Cards = 26

Hearts = 13

Answer

13/26

=1/2

---

## Example 2

Class

30 Boys

20 Girls

10 Boys wear spectacles

Question

Given student is Boy

Probability spectacles?

Sample Space

Only Boys

Answer

10/30

=1/3

---

## Example 3

Dice

Given number is Even

Sample Space

{2,4,6}

Question

Probability number >4

Only 6

Answer

1/3

---

## Very Important

These are NOT the same.

P(Cricket | Boy)

≠

P(Boy | Cricket)

Always see what comes after "Given".

That becomes the denominator.

---

# First Success Probability

Success Probability = p

Failure Probability = 1-p

Probability of First Success on nth attempt

=(1-p)^(n-1) × p

Example

Dice

First 6 on 4th roll

=(5/6)^3 × (1/6)

---

# Cheat Sheet

Probability

P(E)

= Favourable / Total

Complement

1−P(A)

Expected Value

ΣxP(x)

Variance

E(X²)−(E(X))²

Conditional Probability

P(A∣B)

=P(A∩B)/P(B)

Expected Attempts till First Success

1/p

Probability of First Success on nth attempt

(1-p)^(n-1) × p

---

# Things to Remember

✅ Probability is always between 0 and 1.

✅ Expected Value = Average over many trials.

✅ Variance = Spread from Mean.

✅ Whenever "Given" appears,
change the sample space.

✅ Don't memorize formulas blindly.

Always understand what the denominator represents.
