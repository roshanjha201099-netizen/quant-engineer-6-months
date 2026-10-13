#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int n;
    cin >> n;

    /*
        Sabse pehle imagine karo ki hum har product ko B[i] mein
        khareedna chahte hain.

        Total cost:
            sum(B[i])

        Problem:
            B[i] use karne ke liye 1 coupon chahiye,
            aur starting mein hamare paas 0 coupons hain.

        Isliye kuch products ko A[i] mein khareedna padega.
        A[i] mein khareedne par:
            - A[i] pay karenge
            - 1 coupon milega

        Agar product i ko B ki jagah A mein khareedte hain,
        toh extra paisa lagega:

            A[i] - B[i]

        Humein coupon generate karne ke liye aise products
        choose karne hain jinka A[i] - B[i] minimum ho.
    */

    int sumB = 0;
    int minA = LLONG_MAX;

    // diff[i] = A[i] - B[i]
    vector<int> diff(n);

    for (int i = 0; i < n; i++)
    {
        int A, B;
        cin >> A >> B;

        // Assume kar rahe hain ki ye product B mein khareedenge
        sumB += B;

        // Agar extra A purchases karne pade,
        // toh sabse sasta A lena best hoga.
        minA = min(minA, A);

        // B se A par switch karne ka extra cost
        diff[i] = A - B;
    }

    /*
        Humein smallest A-B wale products ko pehle A mein
        khareedna chahiye.

        Example:

            A = 5 5 5 5
            B = 1 2 3 4

            A-B = 4 3 2 1

        Sorted:

            1 2 3 4

        Matlab pehle woh products choose honge jahan
        B -> A karne ka extra cost minimum hai.
    */
    sort(diff.begin(), diff.end());

    int answer = LLONG_MAX;

    /*
        k = kitne products ko hum A price par khareedenge.

        In k products ke liye:
            B ki jagah A dena padega.

        Isliye extra cost =
            diff[0] + diff[1] + ... + diff[k-1]

        Isko baar-baar calculate karne ke bajaye prefix sum
        ki tarah 'extraCost' maintain karenge.
    */
    int extraCost = 0;

    for (int k = 0; k <= n; k++)
    {
        /*
            Ab maan lo k products A mein khareede.

            Har A purchase:
                +1 coupon

            Baaki n-k products B mein khareedne hain.

            Har B purchase:
                -1 coupon

            Total coupon requirement:

                (n-k) - k
                = n - 2*k

            Agar ye positive hai, toh itne aur coupons chahiye.

            Ye coupons generate karne ke liye extra products
            ko A mein khareedna padega.

            Isliye:

                extraA = max(0, n - 2*k)
        */
        int extraA = max(0LL, n - 2 * k);

        /*
            Total cost:

            1. sumB
               Sab products ko B mein lene ka base cost.

            2. extraCost
               k selected products ko B se A mein convert
               karne ka extra cost.

            3. extraA * minA
               Agar coupons abhi bhi kam hain, toh extraA
               products ko cheapest A price par khareedna padega.
        */
        int currentCost =
            sumB
            + extraCost
            + extraA * minA;

        answer = min(answer, currentCost);

        /*
            Next iteration mein k + 1 products A mein honge.

            Isliye next smallest difference add kar do.
        */
        if (k < n)
        {
            extraCost += diff[k];
        }
    }

    cout << answer << '\n';
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--)
    {
        solve();
    }

    return 0;
}