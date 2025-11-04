# SE Lab 6: Fuzzing

> Nathan Matthew Paul
> Section: F
> SRN: PES2UG23CS368
> Date: 2025-10-31

Screenshot-1

![[Pasted image 20251031101212.png]]

![[Pasted image 20251031102027.png]]

Error discovered after fuzzing. ^^

Screenshot-2a

![[Pasted image 20251031101715.png]]

Screenshot-2b

![[Pasted image 20251031110735.png]]

Screenshot-3

![[Pasted image 20251031102054.png]]

Screenshot-4

![[Pasted image 20251031100352.png]]

---

## **Reflection Answers**

1. How did Hypothesis help?

Hypothesis automatically generated a wide range of random and unexpected inputs including edge cases like `None`, empty strings, and malformed data that helped uncover hidden crashes in the code. Instead of manually writing many test cases, Hypothesis explored inputs I wouldn’t have thought of, quickly exposing `AttributeError` and `ValueError` bugs in the `sanitize_string`, `parse_int_list`, and `reverse_words` functions. This demonstrated how property-based fuzz testing can find edge-case failures efficiently.

---

2. What would you use Fuzzing in CI/CD Pipelines?

Integrating fuzz testing in CI/CD ensures continuous detection of robustness and input validation issues as code evolves. Every new commit or merge can automatically run fuzz-based tests to catch crashes, type errors, or security vulnerabilities early in the development cycle. This strengthens software reliability, prevents regressions, and enhances overall quality without requiring manual test creation for every possible input.

---

3. What do you observe from the screenshots SS2a and SS2b?  Justify your answer.

- **SS2a** (before fixing): Hypothesis tests failed, showing that the functions crashed on edge inputs like `None` or malformed strings. This indicates missing input validation and poor error handling.
- **SS2b** (after fixing): All Hypothesis tests passed, confirming that the modified code handled unexpected inputs safely and robustly.
    The difference between SS2a and SS2b demonstrates how fuzz testing guided the debugging process — the same tests that initially broke now validate that the functions are resilient against any input.

