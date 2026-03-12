# financial-portfolio

A C program that reads bank transaction data, separates credits and debits, categorizes income and expenses, computes Indian income tax liability under the new tax regime, and generates a personalized financial advice report.

---

## Overview

This tool takes a `transactions.csv` file as input and produces four output files: separated credit/debit records, a categorized expense breakdown with tax deductibles, an Income Tax Return summary, and a financial advice report.

---

## Project Structure

```
financial-portfolio/
├── data.h              # Shared struct and function declarations
├── input.c             # Reads transactions.csv into memory
├── credit_debit.c      # Splits transactions into credit.csv and debit.csv
├── income.c            # Categorizes credits, applies standard deductions
├── expenses.c          # Categorizes debits, computes eligible deductions
├── tax.c               # Computes tax under new regime, applies 87A rebate + cess
├── advice.c            # Writes financial advice to advice.txt
├── total.c             # main() — orchestrates the full pipeline
├── total.mk            # Makefile
└── transactions.csv    # Input file (your bank statement)
```

---

## Input Format

`transactions.csv` must have this header and structure:

```
Date,Description,Credit,Debit,Balance
2024-04-01,Salary,85000.00,0.0,85000.00
2024-04-05,Groceries,0.0,3200.00,81800.00
...
```

Up to **1024 transactions** are supported.

---

## Output Files

| File | Contents |
|------|----------|
| `credit.csv` | All credit transactions |
| `debit.csv` | All debit transactions |
| `expenses.csv` | Categorized income + debit breakdown with deductibles |
| `Income Tax Returns.csv` | Full ITR — taxable income, slab-wise tax, rebate, cess |
| `advice.txt` | Personalized financial advice |

---

## Tax Computation (New Regime, FY 2024-25)

| Slab | Rate |
|------|------|
| 0 – 3,00,000 | 0% |
| 3,00,001 – 6,00,000 | 5% |
| 6,00,001 – 9,00,000 | 10% |
| 9,00,001 – 12,00,000 | 15% |
| 12,00,001 – 15,00,000 | 20% |
| Above 15,00,000 | 30% |

- **Rebate u/s 87A:** ₹25,000 if total tax < ₹7,00,000
- **Health & Education Cess:** 4% on total tax

---

## Deductions Applied

**Credits:**
- Salary → ₹50,000 standard deduction
- FD Interest → ₹10,000 (80TTA)

**Debits:**
- Home Loan / Loan → ₹2,00,000 (80C & 80EEA)
- Emergency Fund + Retirement Contribution → fully exempt if invested in PPF/ELSS/NPS (80C & 80CCD)
- Health Insurance → ₹50,000 (family) or ₹25,000 (self) under 80D
- Stock Investment → ₹1,00,000 (LTCG exemption)

The program interactively asks two questions at runtime to determine deduction eligibility.

---

## How to Build and Run

```bash
# Build
make -f total.mk

# Run
./a
```

Make sure `transactions.csv` is in the same directory before running.

---

## Description Keywords (used for categorization)

| Category | Matched descriptions |
|----------|----------------------|
| Salary | anything not matched below |
| FD Interest | `FD Interest` |
| Freelance Project | `Freelance Project` |
| Lottery Win | `Lottery Win` |
| Legal Settlement | `Legal Settlement` |
| Emergency Fund | `Emergency Fund` |
| Health Insurance | `Insurance`, `Health Insurance` |
| Retirement | `Retirement Contribution` |
| Stock Investment | `Stock Investment` |
| Loan | `Home Loan`, `Loan` |
| General Expenses | everything else |

---

## Tech Stack

- **Language:** C (C11)
- **Compiler:** GCC
- **Build:** GNU Make
- **I/O:** CSV files (no external libraries)

---

## Author

**Vivian Sobers E** — [github.com/VivianSobers](https://github.com/VivianSobers)
