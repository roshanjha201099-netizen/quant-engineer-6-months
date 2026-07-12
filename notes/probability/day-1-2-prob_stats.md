# Probability & Statistics - Day 1

---

# 1. Probability Basics

## Definition

Probability = Chance of an event happening.

## Formula

P(E) = Favourable Outcomes / Total Outcomes

Example:

Dice
      "name": "Luxurious Goa Escape",
      "duration": "4N/5D",
      "duration_details": [
        "4N Goa"
      ],
      "features": [
        "4 Star Hotel",
        "Airport Pickup & Drop",
        "1 Activity",
        "Selected Meals",
        "Monsoon Experience at Dabhal"
      ],
      "price": "₹17,337 /Person",
      "details_url": ""
    },
    {
      "name": "Candolim Vacation Package",
      "duration": "4N/5D",
      "duration_details": [
        "4N Goa"
      ],
      "features": [
        "4 Star Hotel",
        "Airport Pickup & Drop",
        "1 Activity",
        "Selected Meals",
        "Boat Party with Water Sports"
      ],
      "price": "₹15,786 /Person",
      "details_url": ""
    },
    {
      "name": "Hidden Shores of North Goa Beaches",
      "duration": "4N/5D",
      "duration_details": [
        "4N Goa"
      ],
      "features": [
        "4 Star Hotel",
        "Airport Pickup & Drop",
        "Selected Meals"
      ],
      "price": "₹14,671 /Person",
      "details_url": ""
    },
    {
      "name": "Lavish Goa Retreat",
      "duration": "4N/5D",
      "duration_details": [
        "4N Goa"
      ],
      "features": [
        "5 Star Hotel",
        "Airport Pickup & Drop",
        "1 Activity",
        "Selected Meals"
      ],
      "price": "₹18,296 /Person",
      "details_url": ""
    },
    {
      "name": "Amazing Goa Flight Inclusive Deal 4N",
      "duration": "4N/5D",
      "duration_details": [
        "4N Goa"
      ],
      "features": [
        "4 Star Hotels",
        "Airport Pickup & Drop",
        "2 Activities",
        "Selected Meals",
        "South Goa Sightseeing",
        "Private Transfers"
      ],
      "price": "₹11,806 /Person",
      "details_url": ""
    },
    {
      "name": "Shining Sand Beach hotel Baga",
      "duration": "4N/5D",
      "duration_details": [
        "4N Goa"
      ],
      "features": [
        "4 Star Hotel",
        "Selected Meals"
      ],
      "price": "₹14,052 /Person",
      "details_url": ""
    },
    {
      "name": "Tranquil Morjim Seaside Holiday",
      "duration": "4N/5D",
      "duration_details": [
        "4N Goa"
      ],
      "features": [
        "4 Star Hotel",
        "Airport Pickup & Drop",
        "1 Activity",
        "Selected Meals",
        "North Goa Sightseeing"
      ],
      "price": "₹12,959 /Person",
      "details_url": ""
    },
    {
      "name": "Serene Mandrem Resort Stay",
      "duration": "4N/5D",
      "duration_details": [
        "4N Goa"
      ],
      "features": [
        "4 Star Hotel",
        "Selected Meals"
      ],
      "price": "₹9,781 /Person",
      "details_url": ""
    }
  ]
 

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




{
  "destination": "Goa",
  "departure": "New Delhi",
  "departureDate": "2026-08-20",
  "packageListUrl": "https://holidayz.makemytrip.com/holidays/india/search?fromSearchWidget=true&searchDep=Goa&dest=Goa&destValue=Goa&depCity=New%20Delhi&initd=searchwidget_landing_Goa_notheme&dateSearched=20%2F08%2F2026&glp=true&pdo=true&rooms=2%2C0%2C0%2C0%2C%2C%2C&affiliate=MMT&version=2&sorterPrice=1&duration=4_4",
  "packageList": [
    {
      "name": "Most Wanted Goa Premium Package",
      "duration": "4N/5D",
      "duration_details": [
        "4N Goa"
      ],
      "features": [
        "4 Star Hotel",
        "Airport Pickup & Drop",
        "1 Activity",
        "Selected Meals",
        "Night Tour"
      ],
      "price": "₹14,955 /Person",
      "details_url": ""
    },
    {
      "name": "Magical Hampi & Goa Retreat",
      "duration": "4N/5D",
      "duration_details": [
        "2N Goa",
        "1N Hampi",
        "1N Goa"
      ],
      "features": [
        "Intercity Car Transfers",
        "3 Star Hotels",
        "Airport Pickup & Drop",
        "2 Activities",
        "Selected Meals",
        "Visit to Basilica of Bom Jesus, The Church of Our Lady of Immaculate Conception, Sinquerim Beach",
        "Visit to Virupaksha Temple"
      ],
      "price": "₹23,332 /Person",
      "details_url": ""
    },
    {

        {
  "title": "Amazing Goa Flight Inclusive Deal 4N",
  "url": "https://holidayz.makemytrip.com/holidays/india/package?fromSearchWidget=true&searchDep=Goa&dest=Goa&destValue=Goa&depCity=New%20Delhi&initd=searchwidget_landing_Goa_notheme&dateSearched=20%2F08%2F2026&glp=true&pdo=true&rooms=2%2C0%2C0%2C0%2C%2C%2C&affiliate=MMT&version=2&sorterPrice=1&duration=4_4&id=23726&listingClassId=4298&depDate=2026-08-20&fromCity=New%20Delhi&variantId=NO_MAJOR_COMMUTE_CCCDEC54&room=2%2C0%2C0%2C0%2C%2C%2C&searchDate=2026-08-20&pkgType=FIT",
  "itenary": [
    "Flights Flights Hotels Hotels Homestays & Villas Homestays & Villas Holiday Packages Holiday Packages Trains Trains Buses Buses Cabs Cabs Visa Visa Forex Card & Currency Forex Card & Currency Travel Insurance Travel Insurance More More Where2Go Giftcards Tours & Attractions Cruise Agent Login Login as expert M Hi Mohd STARTING FROM TRAVELLING ON ROOMS & GUESTS Search Please note that the start city of your package is Goa Amazing Goa Flight Inclusive Deal 4N Highlights Customise the package as per need Just your friends/family Customizable 4N/5D 4N Goa VIEW GALLERY → Activities & Sightseeing Property photos ITINERARY POLICIES SUMMARY Add-ons included Insurance 5 Day Plan 2 Transfers 2 Hotels 2 Activities 4 Meals Day Plan 20 Aug, Thu 21 Aug, Fri 22 Aug, Sat 23 Aug, Sun 24 Aug, Mon Day 1 Goa INCLUDED : 1 Hotel 1 Transfer FLIGHT Arrival in Goa Please Note : You need to reach Goa on your own There are more ways to reach your destination VIEW TRANSPORT OPTION(S) TRANSFER Airport to hotel in Goa Remove Modify Private Transfer Travel comfortably in a private vehicle from either Goa Airports to your hotel in Goa.\n\nNote: The pick-up timing is Read More... Airport to Hotel RESORT 3 Nights In Goa Split Stay Remove Change 1+ View All 4 Very Good (718 Ratings) Summit Calangute Resort & Spa Calangute | 2.2 km drive to Calangute Beach 1 Room | 2 Adults 20th Aug 2 PM - 23rd Aug 12 PM, 3 Nights Deluxe Room with Private Balcony -  Holidays Selections More Room Options (King Bed | City View) Breakfast is included Signature Activities & Experiences Early Check-In upto 2 hours (subject to availability) Late Check-Out upto 2 hours (subject to availability) Read More Add Activities to your day Spend the day at leisure or add an activity, transfer or meal to your day ADD TO DAY Day 2 Goa INCLUDED : 1 Meal MEAL Breakfast In Goa Add Activities to your day Spend the day at leisure or add an activity, transfer or meal to your day ADD TO DAY Day 3 Goa INCLUDED : 1 Meal MEAL Breakfast In Goa Add Activities to your day Spend the day at leisure or add an activity, transfer or meal to your day ADD TO DAY Day 4 Goa INCLUDED : 1 Hotel 2 Activities 1 Meal MEAL Breakfast In Goa TRANSFER 1 Hour Inter-Hotel Transfers (North Goa to South Goa) Enjoy comfortable transfers from one hotel in Goa to another hotel in Goa by a private vehicle. Sit back and relax as you take in the coastal views along the way. Private, Private Car ACTIVITY 9 Hours In Goa South Goa Sightseeing from North Goa Hotel Explore the pristine beaches and soak in the old-world charm of Portuguese architecture in South Goa. Visit historical landmarks and idyllic beaches and indulge in a local shopping spree with this sightseeing activity.\n\nNote: Two-way transf Read More... South Goa Sightseeing (N Goa) Duration 9 Hours | Morning Pick up and Drop is included View More Options HOTEL CHECKOUT In Goa RESORT 1 Night In Goa Remove Change 1+ View All 3.9 Very Good (776 Ratings) SALCETE BEACH RESORT Colva | 5 minutes walk to Colva Beach 1 Room | 2 Adults 23rd Aug 1 PM - 24th Aug 11 AM, 1 Night Executive Room More Room Options (King Bed | Garden View) Breakfast is included Complimentary Hi-Tea 10% off on Food & Beverages Complimentary welcome drinks on arrival Add Activities to your day Spend the day at leisure or add an activity, transfer or meal to your day ADD TO DAY Day 5 Goa INCLUDED : 1 Transfer 1 Meal MEAL Breakfast In Goa HOTEL CHECKOUT In Goa TRANSFER Hotel in Goa to Airport Remove Modify Private Transfer Travel comfortably in a private vehicle from your hotel to either of the two airports in Goa.\n\nNote: The pick-up ti Read More... Hotel to Airport FLIGHT Departure from Goa Please Note : You need to depart from Goa on your own Add Activities to your day Spend the day at leisure or add an activity, transfer or meal to your day ADD TO DAY Your Goa Destination Guide Discover the best of Goa with our Split-Stay Adventure: vibrant nightlife in North Goa and serene relaxation in South Goa, offering the perfect blend of excitement and tranquility. Read More ₹12,052 2% OFF ₹0 /Adult Excluding applicable taxes PROCEED TO PAYMENT Create Quote Crm Pax Association Bank Offers up to 25% OFF Don’t Miss Out – Use Bank Coupons for Extra Discounts! Coupons & Offers ₹ EMI No cost EMI @ ₹3,935 Book your holidays with Easy EMI options . Have a Coupon Code? Enter Code BREAKFREE - ₹164 Coupon Applied successfully! Remove MMTHLD - ₹77 Grab Your Discount Before It’s Gone! Apply"
  ],
  "policies": [],
  "summary": [],
  "activites": [],
  "hotels": [],
  "transfers": []
}