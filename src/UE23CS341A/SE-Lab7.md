# SE Lab 7: Code & Branch Coverage

> Nathan Matthew Paul
> Section: F
> SRN: PES2UG23CS368
> Date: 2025-11-07

---

## Before Fixing

![[Screenshot 2025-11-07 at 09.15.04.png]]

![[Screenshot 2025-11-07 at 09.15.21.png]]

![[Screenshot 2025-11-07 at 09.19.05.png]]

## After Fixing

![[Screenshot 2025-11-07 at 09.37.09.png]]

![[Screenshot 2025-11-07 at 09.38.19.png]]

![[Screenshot 2025-11-07 at 09.38.26.png]]

![[Screenshot 2025-11-07 at 09.38.39.png]]

---

#  Reflection

## 1. If the logic in order_processor.py changes, what’s your strategy to ensure tests and coverage stay updated?

If the logic changes, I would first review what part of the behavior has been modified. Then I would update the existing test cases so they match the new expected results and add new test cases if the changes introduce new conditions or branches. After that, I would run the coverage report again to make sure all new or updated logic is fully covered. This ensures the tests always reflect the current functionality of the code.

## 2. What are the trade-offs between writing more tests for coverage vs writing fewer high-quality tests?

Writing more tests can increase coverage and catch more edge cases, but it can also lead to many repetitive or low-value tests that take time to maintain. Writing fewer high-quality tests is faster and easier to maintain, but it may leave some code paths untested, increasing the chance of hidden bugs. The best approach is to balance both: aim for meaningful tests that cover important branches and behaviors without writing unnecessary ones.