#  BC: Lab 1

> Submission Date: 2026-01-30
> Name: **Nathan Matthew Paul**
> SRN: **PES2UG23CS368**
> Section: 6F

---

## Part 1: Intro to MetaMask

### Account 1

![[Screenshot 2026-02-01 at 15.43.34.png]]

![[Pasted image 20260201160622.png]]

### Account 2

![[Screenshot 2026-02-01 at 15.46.32.png]]

![[Pasted image 20260201160701.png]]

### Before Sending

![[Pasted image 20260201160804.png]]

![[Pasted image 20260201160701.png]]

### After Sending

![[Pasted image 20260201160909.png]]

![[Pasted image 20260201160954.png]]

![[Pasted image 20260201161107.png]]
---

## Part 2: Bitcoin

**a. How many transactions are there in the Genesis block in Bitcoin?**
- There is **only 1 transaction**

**b. Who mined this block, and what was the block reward?**
- It was mined by **Satoshi Nakamoto** (coins are credited to address `1A1zP1eP5QGefi2DMPTfTL5SLmv7DivfNa`).
- The block reward was **50 BTC** (though these coins are unspendable).

---

**a. How many transactions are there in the Genesis block in Ethereum (other than the transaction for miner fee)?**
- 8893 txns but
- Ethereum’s actual genesis block (`0`) has **0 transactions** recorded on the public explorer (other than internal allocations).

**b. What is hash of the parent block? What are your observations?**

- The **parent hash** field of Ethereum’s genesis block is all zeros (`0x000...0`).
- **Observations:** Since this is the very first block, there is no parent block it _starts_ the blockchain. This is typical for all genesis blocks.

---

**a. What is the hash of the previous block for Bitcoin block #490624?**

> `0000000000000000004239f2a01d8f579bc0dbb214d0f874ece5db587bee3457`

---

**a. How many transactions are recorded in block #1?**
- **0 transactions**

**b. Who mined this block, and what was the block reward?**
- **Mined by:** `0x05a56E2D52c817161883f50c441c3228CFe54d9f`
- **Block reward:** **5 ETH**

**c. What is the hash of the block?**
- **Block Hash:** `0x88e96d4537bea4d9c05d12549907b32561d3bf31f45aae734cdc119f13406cb6`

**d. What is the hash of the parent?**
- **Parent Hash:** `0xd4e56740f876aef8c010b86a40d5f56745a118d0906a34e69aec8c0db1cb8fa3`

---

**a. Approximately, how many Ethers are transferred in this transaction?**
- **~913.27 ETH** were transferred.

**b. What is the address of the sender in this transaction?**
- **Sender:** `0xF9fbA58d8345bD3100C5AdF3b8B51938E5dA0a9D`

**c. What is the Transaction Action?**
- **Action:** Transfer of ~913.27 ETH.

---

## Part 3: Exercise

**1) Why does blockchain use a Secret Recovery Phrase?**

- A **Secret Recovery Phrase** (seed phrase) is a set of words that _represents your wallet’s private key_.
- It lets you **restore your wallet and access your funds** on any device.
- Sharing it with others allows them full control over your crypto so it must be kept _secret_.

**2) What are Gas Fees in Ethereum, and why are they required?**

- **Gas fees** are small payments in ETH required to execute transactions or smart contracts.
- They compensate **validators** for securing and processing transactions, and prevent abuse of network resources.

**3) Why do blockchain transactions take time instead of happening instantly?**

- Transactions must be **verified and added to a block** by miners/validators.
- This process takes time because networks reach _consensus_ and must confirm the transaction before it’s final.

**4) What is a Testnet Faucet and how does it help?**

- A **Testnet Faucet** provides _free testnet tokens_ (not real crypto) to developers.
- These help testers run transactions without risking actual ETH.

**5) Why should you never share your private key?**

- A **private key** gives complete access to your wallet.
- Sharing it would allow anyone to **steal or control your assets** instantly.