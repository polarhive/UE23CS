# SE Lab 5: Static Code Analysis

> Nathan Matthew Paul
> Section: F
> SRN: PES2UG23CS368
> Date: 2025-10-27

----

## 1. Issue Table (Before Fixes)

| **Issue**                                                | **Type**         | **Line(s)** | **Description**                                                                                | **Fix Approach**                                                                                       |
| -------------------------------------------------------- | ---------------- | ----------- | ---------------------------------------------------------------------------------------------- | ------------------------------------------------------------------------------------------------------ |
| Mutable default argument (`logs=[]`)                     | Bug              | 8           | Default mutable list is shared across function calls, which can cause unintended side effects. | Change default to `None` and initialize inside the function.                                           |
| Bare `except:` (no exception type)                       | Security / Logic | 19          | Broad exception handling hides actual errors and causes silent failures.                       | Replace with a specific exception type (e.g., `except KeyError:`) and log the error.                   |
| Insecure use of `eval()`                                 | Security         | 59          | `eval()` executes arbitrary code, which is a major security vulnerability (CWE-78).            | Remove or replace with a safe alternative (e.g., `print()` or `ast.literal_eval()` if parsing needed). |
| File handling without context manager                    | Maintainability  | 26, 32      | Files are opened without `with`, risking resource leaks or corruption.                         | Use `with open(...) as f:` to ensure safe file closing and resource management.                        |
| Unused import (`logging`)                                | Style            | 2           | The module `logging` is imported but never used.                                               | Remove unused import or integrate proper logging functionality.                                        |
| Missing docstrings                                       | Style            | Multiple    | Functions and module lack docstrings, reducing readability and maintainability.                | Add descriptive docstrings following PEP 257 conventions.                                              |
| Naming not in snake_case (e.g., `addItem`, `removeItem`) | Style            | Multiple    | Function names don’t follow PEP 8 naming conventions.                                          | Rename functions using snake_case (e.g., `add_item`, `remove_item`).                                   |
| Formatting / Blank line errors                           | Style            | Multiple    | Missing blank lines between functions and after definitions (E302, E305).                      | Add proper spacing for readability and PEP 8 compliance.                                               |

---

## 2. Fixed Code

```python
"""Inventory system module for managing stock items."""

import json
import logging
from datetime import datetime

# Global variable
stock_data = {}


def add_item(item="default", qty=0, logs=None):
    """Add an item and its quantity to stock."""
    if logs is None:
        logs = []
    if not isinstance(item, str) or not isinstance(qty, int):
        logging.warning("Invalid types for item or quantity.")
        return
    stock_data[item] = stock_data.get(item, 0) + qty
    logs.append(f"{datetime.now()}: Added {qty} of {item}")


def remove_item(item, qty):
    """Remove quantity of an item from stock safely."""
    try:
        stock_data[item] -= qty
        if stock_data[item] <= 0:
            del stock_data[item]
    except KeyError:
        logging.warning("Attempted to remove non-existent item: %s", item)


def get_qty(item):
    """Return quantity of an item."""
    return stock_data.get(item, 0)


def load_data(file="inventory.json"):
    """Load stock data from a JSON file."""
    try:
        with open(file, "r", encoding="utf-8") as f:
            data = json.load(f)
            stock_data.clear()
            stock_data.update(data)
    except (FileNotFoundError, json.JSONDecodeError) as err:
        logging.error("Error loading data: %s", err)
        stock_data.clear()


def save_data(file="inventory.json"):
    """Save stock data to a JSON file."""
    with open(file, "w", encoding="utf-8") as f:
        json.dump(stock_data, f, indent=4)


def print_data():
    """Print a summary report of all stock items."""
    print("Items Report")
    for item, qty in stock_data.items():
        print(f"{item} -> {qty}")


def check_low_items(threshold=5):
    """Return a list of items below a stock threshold."""
    return [item for item, qty in stock_data.items() if qty < threshold]


def main():
    """Main function for demonstration."""
    add_item("apple", 10)
    add_item("banana", -2)
    add_item("pear", 5)
    remove_item("apple", 3)
    remove_item("orange", 1)
    print(f"Apple stock: {get_qty('apple')}")
    print(f"Low items: {check_low_items()}")
    save_data()
    load_data()
    print_data()


if __name__ == "__main__":
    main()
```

![[Pasted image 20251027114006.png]]

### Post fixing

![[Screenshot 2025-10-27 at 12.53.49 1.png]]

![[Screenshot 2025-10-27 at 12.54.28 1.png]]

![[Screenshot 2025-10-27 at 12.54.42 1.png]]

---

## 3. Reflection

1. Easiest and hardest issues:

The easiest fixes were spacing and docstring issues flagged by Flake8 and Pylint. The hardest was rewriting unsafe code (removing eval()) while keeping functionality intact.

2. False positives:

Bandit’s try-except-pass warning was technically correct but low severity in this context; still, better logging was implemented.

3. Integration into workflow:

I would add these tools into a GitHub Actions CI pipeline or pre-commit hook to automatically lint and secure code before merge.

4. Code improvements observed:

Readability, safety, and maintainability improved significantly. Using context managers, type validation, and logging made the program more robust and professional.
