
// This code defines a solution to identify invalid transactions based on specific criteria.
// Invalid transactions are those that either exceed a certain amount or occur within a certain time frame in different cities for the same individual.

// Time: worst case O(n^2) where n is the number of transactions, as we may need to compare each transaction with every other transaction for the same name.
// Avg case time complexity is O(n^2 /k where k = no. of distincit names) if transactions are well distributed across names and cities.
// Space: O(n) for storing parsed transactions and mapping names to their indices.

// Questions to ask in interview:
// - What is the format of the transaction string? (name,time,amount,city)
// - What are the criteria for a transaction to be considered invalid?
// - can both the transactions be invalid or any one of them can be invalid? (both can be invalid)
// - What is the maximum number of transactions? (to understand time complexity implications)
// - can name and city be case sensitive or contain any special charcters? or should i assume only lower case letters? (assume only lowercase letters)
/*
* Parsing: Split each transaction string by commas into name, time, amount, city. 
* Store in a struct array, and simultaneously build a hash map (byName) that groups transaction indices by name.
* this avoids comparing every transaction against every other transaction (only against ones sharing the same name).
*/

/*
*  Checking for invalid transactions:
*  amount > 1000 -> invalid
*  Otherwise, look only at transactions with the same name (from the map) and check if any of them is in a different city and within 60 minutes (abs(time difference) <= 60). mark invalid.
*/

#include <vector>
#include <string>
#include <unordered_map>
#include <sstream>
using namespace std;

struct Txn {
    string name;
    int time;
    int amount;
    string city;
};

class Solution {
public:
    vector<string> invalidTransactions(vector<string>& transactions) {
        int n = transactions.size();
        vector<Txn> parsed(n);
        unordered_map<string, vector<int>> byName; // name -> indices

        // Parse each transaction string
        for (int i = 0; i < n; i++) {
            stringstream ss(transactions[i]);
            string token;
            vector<string> parts;
            while (getline(ss, token, ',')) {
                parts.push_back(token);
            }
            parsed[i] = { parts[0], stoi(parts[1]), stoi(parts[2]), parts[3] };
            byName[parsed[i].name].push_back(i);
        }

        vector<string> result;

        for (int i = 0; i < n; i++) {
            bool invalid = false;

            // Condition 1: amount exceeds 1000
            if (parsed[i].amount > 1000) {
                invalid = true;
            }

            // Condition 2: check against same-name transactions
            if (!invalid) {
                for (int j : byName[parsed[i].name]) {
                    if (j == i) continue;
                    if (parsed[i].city != parsed[j].city &&
                        abs(parsed[i].time - parsed[j].time) <= 60) {
                        invalid = true;
                        break;
                    }
                }
            }

            if (invalid) {
                result.push_back(transactions[i]);
            }
        }

        return result;
    }
};