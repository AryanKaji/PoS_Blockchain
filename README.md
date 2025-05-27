# Proof-of-Stake Blockchain Simulator in C++

This project is a simple blockchain simulation written in C++ that demonstrates how a **Proof-of-Stake (PoS)** consensus mechanism works.
---

## Features

- Block creation with:
  - Timestamp
  - SHA-256 hashing (via OpenSSL)
  - Validator selection based on stake
- Dynamic validator reward system
- Prints full blockchain and validator stakes
---

## How It Works

- Genesis block is created by `"System"`.
- Validators are selected randomly based on their stake proportion.
- Every time a validator successfully adds a block, they are rewarded with additional stake.
- Each block includes:
  - Index
  - Timestamp
  - Data (transaction info)
  - Validator
  - Previous hash
  - Current block hash
---

## Dependencies

- **C++17 or later**
- **OpenSSL** for SHA-256 hashing
---

## Output
```bash
Block #1 added by Alice
Hash: 912aab38f57d7378c2020e9c7a5217f073cfba892ad3b2b65416213fcb32b1e6
Validator Alice rewarded with +10. New stake: 60
Current Stakes:
- Alice: 60
- Bob: 30
- Charlie: 20
===============================

Block #2 added by Bob
Hash: 789bcef53f593983e8679f78cfca8c7f5096f24d63d353f1d118fce75ec87530
Validator Bob rewarded with +10. New stake: 40
Current Stakes:
- Alice: 60
- Bob: 40
- Charlie: 20
===============================

Block #3 added by Alice
Hash: 4f299d2f01011a3210adffde8c89ea5f8e06fef3f6ef527f7e279130fd0bfc84
Validator Alice rewarded with +10. New stake: 70
Current Stakes:
- Alice: 70
- Bob: 40
- Charlie: 20
===============================


=== Final Blockchain ===
Block #0 [Mon May 27 23:05:12 2025]
Validator: System
Data: Genesis Block
Prev Hash: 0
Hash: 949679bb3556f48698e7d2f89c83294c5ee6e998a21b7cd109d30e67eeb99a43
-------------------------------

Block #1 [Mon May 27 23:05:12 2025]
Validator: Alice
Data: Alice sent 5 coins to Bob
Prev Hash: 949679bb3556f48698e7d2f89c83294c5ee6e998a21b7cd109d30e67eeb99a43
Hash: 912aab38f57d7378c2020e9c7a5217f073cfba892ad3b2b65416213fcb32b1e6
-------------------------------

Block #2 [Mon May 27 23:05:12 2025]
Validator: Bob
Data: Bob sent 2 coins to Charlie
Prev Hash: 912aab38f57d7378c2020e9c7a5217f073cfba892ad3b2b65416213fcb32b1e6
Hash: 789bcef53f593983e8679f78cfca8c7f5096f24d63d353f1d118fce75ec87530
-------------------------------

Block #3 [Mon May 27 23:05:12 2025]
Validator: Alice
Data: Charlie sent 1 coin to Alice
Prev Hash: 789bcef53f593983e8679f78cfca8c7f5096f24d63d353f1d118fce75ec87530
Hash: 4f299d2f01011a3210adffde8c89ea5f8e06fef3f6ef527f7e279130fd0bfc84
-------------------------------
```
---
