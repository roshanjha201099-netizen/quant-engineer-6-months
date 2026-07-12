# Probability & Statistics - Day 3

---

# 1. Random Variable

## Intuition

A Random Variable is **NOT** a random number.

A Random Variable is a **function (or rule)** that assigns a numerical value to every possible outcome of a random experiment.

Think of it as a machine.

Outcome
        ↓
Random Variable (X)
        ↓
      Number

---

## Example 1 (Dice)

Sample Space

S = {1,2,3,4,5,6}

Define

X = Number on the top face.

Then

X(1)=1

X(2)=2

X(3)=3

X(4)=4

X(5)=5

X(6)=6

---

## Example 2

Define

X = 1 if Even

X = 0 if Odd

Then

X(1)=0

X(2)=1

X(3)=0

X(4)=1

X(5)=0

X(6)=1

Notice:

Same experiment.

Different Random Variable.

---

## Important

Random Variable is the FUNCTION.

X(5)=0 is the VALUE produced by the Random Variable.

---

# 2. Discrete Random Variable

## Definition

A Random Variable is called Discrete if its possible values can be listed.

Examples

Dice

{1,2,3,4,5,6}

Coin

{0,1}

Number of students

0,1,2,3,...

Number of emails received

0,1,2,...

---

## Examples

Discrete

✅ Dice Number

✅ Number of Customers

✅ Number of Calls

✅ Number of Bugs

---

# 3. Continuous Random Variable

## Definition

A Random Variable is Continuous if it can take any value in an interval.

There are infinitely many possible values.

Examples

Height

Weight

Temperature

Time

Distance

Speed

---

## Intuition

Between

170 cm

and

171 cm

there are infinitely many numbers.

170.1

170.01

170.001

170.0001

...

Hence Height is Continuous.

---

# Difference

Discrete

Can count values.

Examples

Coin

Dice

People

Cars

Continuous

Cannot list all values.

Examples

Height

Weight

Time

Temperature

Distance

---

# 4. Probability Mass Function (PMF)

PMF is used ONLY for Discrete Random Variables.

It tells us

Probability of each possible value.

Example

Dice

| X | P(X) |
|---|------|
|1|1/6|
|2|1/6|
|3|1/6|
|4|1/6|
|5|1/6|
|6|1/6|

---

Example

Coin

X=1 (Head)

X=0 (Tail)

| X | P(X) |
|---|------|
|0|1/2|
|1|1/2|

---

## Important Rules

Every probability

0 ≤ P(X=x) ≤ 1

Sum of all probabilities

=1

---

## Very Important Observation

PMF is built on

Random Variable Values

NOT

Sample Space directly.

Example

Outcome

{1,2,3,4,5,6}

Random Variable

Odd → 0

Even → 1

PMF

| X | P(X) |
|---|------|
|0|1/2|
|1|1/2|

Notice

PMF has only TWO rows.

Because Random Variable takes only two values.

---

# 5. Why PMF Fails for Continuous Variables

Suppose

X = Height

Question

P(X = 170 cm)

Answer

0

Reason

There are infinitely many possible heights.

Probability of any one exact value is zero.

Instead we calculate

P(169 ≤ X ≤ 171)

Range probabilities.

This is why PMF cannot be used for Continuous Random Variables.

This motivates the need for PDF.

---

# Key Takeaways

✅ Random Variable is a function.

✅ Outcomes and Random Variable are different.

✅ Discrete Random Variables have countable values.

✅ Continuous Random Variables have infinitely many values in an interval.

✅ PMF is used only for Discrete Random Variables.

✅ PMF stores probability of every possible value.

✅ Sum of PMF probabilities is always 1.

✅ For Continuous Variables

P(X = exact value) = 0

Hence PMF cannot be used.

This leads to PDF.

---

# Next Topics

- Probability Density Function (PDF)
- Cumulative Distribution Function (CDF)
- Relationship between PMF, PDF and CDF
- Visual intuition using graphs