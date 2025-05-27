#include <iostream>
#include <sstream>
#include <vector>
#include <ctime>
#include <map>
#include <iomanip>
#include <openssl/sha.h>

using namespace std;

class Block {
public:
    int index;
    string previousHash;
    string timestamp;
    string data;
    string validator;
    string hash;

    Block(int idx, const string& data, const string& prevHash, const string& validator) {
        this->index = idx;
        this->data = data;
        this->previousHash = prevHash;
        this->validator = validator;
        time_t now = time(0);
        this->timestamp = string(ctime(&now));
        this->timestamp.pop_back(); // remove newline from timestamp
        this->hash = calculateHash();
    }

    string calculateHash() const {
        string inputStr = to_string(index) + previousHash + timestamp + data + validator;
        unsigned char hash[SHA256_DIGEST_LENGTH];
        const unsigned char* dataBytes = reinterpret_cast<const unsigned char*>(inputStr.c_str());
        SHA256(dataBytes, inputStr.size(), hash);

        stringstream ss;
        for (int i = 0; i < SHA256_DIGEST_LENGTH; ++i) {
            ss << hex << setw(2) << setfill('0') << (int)hash[i];
        }
        return ss.str();
    }

    void display() const {
        cout << "Block #" << index << " [" << timestamp << "]\n";
        cout << "Validator: " << validator << "\n";
        cout << "Data: " << data << "\n";
        cout << "Prev Hash: " << previousHash << "\n";
        cout << "Hash: " << hash << "\n";
        cout << "-------------------------------\n\n";
    }
};

class Blockchain {
private:
    vector<Block> chain;
    map<string, int> stakes;

public:
    Blockchain() {
        // Initial stakes
        stakes["Alice"] = 50;
        stakes["Bob"] = 30;
        stakes["Charlie"] = 20;

        chain.emplace_back(Block(0, "Genesis Block", "0", "System"));
    }

    string selectValidator() {
        int totalStake = 0;
        for (const auto& pair : stakes) {
            totalStake += pair.second;
        }

        int r = rand() % totalStake;
        int cumulative = 0;
        for (const auto& pair : stakes) {
            cumulative += pair.second;
            if (r < cumulative) return pair.first;
        }
        return "System"; // fallback
    }

    void rewardValidator(const string& validator, int amount) {
        stakes[validator] += amount;
        cout << "Validator " << validator << " rewarded with +" << amount
             << " stake. New stake: " << stakes[validator] << "\n";
    }

    void addBlock(const string& data) {
        string validator = selectValidator();
        Block newBlock(chain.size(), data, chain.back().hash, validator);
        chain.push_back(newBlock);

        cout << "Block #" << newBlock.index << " added by " << validator << "\n";
        cout << "Hash: " << newBlock.hash << "\n";
        rewardValidator(validator, 10);
        printStakes();
        cout << "===============================\n\n";
    }

    void printStakes() const {
        cout << "Current Stakes:\n";
        for (const auto& pair : stakes) {
            cout << "- " << pair.first << ": " << pair.second << "\n";
        }
    }

    void displayChain() const {
        for (int i = 0; i < chain.size(); i++) {
            chain[i].display();
        }
    }
};

int main() {
    srand(time(0)); // random seed

    Blockchain bChain;

    bChain.addBlock("Alice sent 5 coins to Bob");
    bChain.addBlock("Bob sent 2 coins to Charlie");
    bChain.addBlock("Charlie sent 1 coin to Alice");

    cout << "\n=== Final Blockchain ===\n";
    bChain.displayChain();

    return 0;
}
