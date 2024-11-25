# Linear Regression and Distribution Free Tests

> P-value: measures the plausibility of H0. The smaller the P-value, the stronger the evidence is against H0.

> [!NOTE]
> In any hypothesis test, we are calculating conditional probabilities based on the assumption that the null hypothesis is true.

If the P-value is sufficiently small, we may be willing to abandon our assumption that H0 is true and believe H1 instead.

This is referred to as rejecting the null hypothesis.

![[Pasted image 20241122125844.png]]

![[Pasted image 20241122125909.png]]'

![[Pasted image 20241122125940.png]]

---

## Chi-squared Test

The Chi-squared test is a non-parametric test used to determine if there is a significant association between categorical variables. It compares the observed frequencies in each category to the frequencies we would expect if there were no association.

The ***test statistic*** is calculated as:

$$
\chi^2 = \sum \frac{(O_i - E_i)^2}{E_i}
$$

- $O_i$ = observed frequency
- $E_i$ = expected frequency, calculated as $E_i = \frac{(row\ total \times column\ total)}{grand\ total}$

Suppose we want to test if there is an association between gender (male, female) and preference for a product (like, dislike). We collect the following data:

|        | Like | Dislike | Total |
| ------ | ---- | ------- | ----- |
| Male   | 30   | 10      | 40    |
| Female | 20   | 40      | 60    |
| Total  | 50   | 50      | 100   |

### Fixed Level Testing

In fixed level testing, the significance level ($\alpha$) is predetermined, typically set at 0.05 or 0.01. This level indicates the probability of making a Type I error.

If $\alpha = 0.05$, we reject the null hypothesis if the p-value is less than 0.05.

### Type I and Type II Errors

- **Type I Error ($\alpha$)**: The probability of rejecting the null hypothesis when it is **true**. For example, concluding that a new drug is effective when it is not.
- **Type II Error ($\beta$)**: The probability of failing to reject the null hypothesis when it is **false**. For example, concluding that a new drug is not effective when it actually is.

#### Situation 1: **You reject H₀ (null hypothesis)**

> You’re testing if the average ($\mu$) is bigger than 15, and you decide H₀ ("average = 15") is wrong.

1. **You’re correct!**: If the real average is actually bigger than 15—you made the **right decision**!
2. **You’re wrong (Type I error):**
	- If the real average is still exactly 15 (H₀ was actually true), you made a **Type I error**.
	- This is like falsely shouting, *"It’s more than 15!"* when it isn’t.
	- The chance of making a Type I error is controlled by $\alpha = 0.05$\, meaning you’re okay with being wrong **5% of the time**.

#### Situation 2: **You do not reject H₀**

> This time, after testing, you decide to **stick with H₀**, saying the average is **still 15**.

1. **You’re correct!**: If the real average is actually 15 (H₀ is true), you made the **right decision**.
2. **You’re wrong (Type II error):**
	- If the real average is actually **bigger than 15** (H₀ was false), you made a **Type II error**
	- This is like missing something important—you quietly say, *"It’s still 15,"* when it’s actually more!
	- The chance of making a Type II error depends on factors like sample size, variability, and how far the true average is from 15.

> [!Example]
> - **Type I error**: You **falsely reject** H₀ (shouting "It’s bigger than 15!" when it isn’t).
> - **Type I error**: You wrongly call an innocent person guilty
> - **Type II error**: You **fail to reject** H₀ (saying "It’s still 15" when it’s actually bigger).
> - **Type II error**: You let a guilty person go free.

---

## Power of a Test

The power of a test is the probability of correctly rejecting the null hypothesis when it is false. It is influenced by several factors: The **power of a test** tells you how good your test is at detecting the truth when **H₀ is false**.

$\text{Power} = 1 - \beta$

### Factors Affecting Power

1. **Sample Size (n)**: Increasing the sample size reduces variability and increases power.
2. **Effect Size**: Larger effect sizes (the difference between the null hypothesis and the true value) increase power.
3. **Significance Level ($\alpha$)**: Increasing $\alpha$ increases power but also increases the risk of Type I error.

---

> [!Quote]
> - Imagine you’re a detective trying to catch a thief (**H₁ is true**—there’s a thief).
> - The **power** of your test is your ability to catch the thief when there really is one. If you’re great at catching thieves, your test has **high power**!

| **Reality**     | **Researcher Decision** | What Happens?                                                   |
| --------------- | ----------------------- | --------------------------------------------------------------- |
| **H₀ is true**  | **Reject H₀**           | **Type I error (α)**: Oops! You accused an innocent person.     |
|                 | **Fail to reject H₀**   | **Correct Decision (1 - α)**: You did nothing, and that’s good. |
| **H₀ is false** | **Reject H₀**           | **Correct Decision (1 - β)**: You caught the thief—great job!   |
|                 | **Fail to reject H₀**   | **Type II error (β)**: You let the thief go free. Oops!         |

#### How is it connected to the table?

- The **power of the test** is **1 - β**.
- It’s the chance you correctly reject H₀ when it’s actually false (you catch the thief when there really is one!).

> [!Example]
> Imagine you’re trying to figure out if a new light bulb lasts longer than 15 hours.
>
> - **H₀ (null hypothesis):** The light bulb lasts 15 hours.
> - **H₁ (alternative hypothesis):** The light bulb lasts more than 15 hours.

When you test the bulbs:

1. **If you reject H₀ (say it lasts more):**
	- **H₀ true**: You’re wrong → **Type I error (α)**.
	- **H₀ false**: You’re right → This is **power (1 - β)**!

2. **If you fail to reject H₀ (say it’s still 15):**
	- **H₀ true**: You’re right → Correct decision ($1 - \alpha$).
	- **H₀ false**: You’re wrong → **Type II error (β)**.

> [!Warning]
> - **Power (1 - β)** = The chance you make the right call when H₀ is false.
> - You want power to be high, so you’re less likely to let a guilty thief (or a false H₀) get away!

> [!Important]
> - The power tells you how likely your test is to catch the truth (reject H₀ when it’s false).
> - A high-power test means **you’re great at spotting when H₁ is true**.

## What are **one-tailed** and **two-tailed** tests?

- A **one-tailed test** checks for a difference in **one direction** only.
    Example: You test if a new medicine is **better** than the old one (not worse or the same).

- A **two-tailed test** checks for a difference in **either direction**.
    Example: You test if a new medicine is **different** (better _or_ worse) than the old one.

---

### Why does **power** differ between one-tailed and two-tailed tests?

- In a **one-tailed test**, you focus all your effort on detecting differences in just one direction. This makes it **easier to detect an effect**, so **one-tailed tests have more power**.
    Example: If you’re only checking if a student’s grades go **up**, you won’t waste time worrying if they go down.

- In a **two-tailed test**, you split your focus between two directions. This makes it harder to detect differences, reducing power.
    Example: If you’re checking if grades go **up or down**, you’re less focused, and it’s harder to detect small changes.

---

### Factors That Affect Power (and why they make sense)

1. **Greater sample size → Higher power**

    - A bigger sample gives you more data, making it easier to detect real differences.
    - Example: If you want to know if chocolate makes people happy, testing 1,000 people will give you a clearer answer than testing just 5.

1. **Larger significance level (α\alphaα) → Higher power**

    - A bigger significance level means you’re more willing to reject the null hypothesis (H₀), so it’s easier to detect a difference.
    - Example: If you’re okay with being wrong 10% of the time (α=0.10\alpha = 0.10α=0.10), you’ll catch more real effects than if you’re super strict and only allow a 5% error rate (α=0.05).

1. **Greater effect size → Higher power**
    - A big effect is easier to spot!
    - Example: If a new medicine makes people _a lot_ healthier, you’ll notice it more easily than if it makes only a tiny improvement.

1. **Smaller standard deviation → Higher power**

    - Less variation in your data makes it easier to see patterns and differences.
    - Example: If everyone’s test scores are close together (small spread), it’s easier to tell if a teaching method works. If scores are all over the place (large spread), it’s harder to tell.

2. **One-tailed test > Two-tailed test (in power)**

    - As explained earlier, one-tailed tests focus on one direction, making it easier to detect differences. Two-tailed tests "divide their attention," reducing power.

---

> [!Example] *Imagine* you’re a detective using a flashlight (hypothesis test) to find a thief (effect).
>
> - A **larger flashlight** (bigger sample size) helps you see more.
> - Being **okay with mistakes** (α) means you search more aggressively, so you catch more thieves but risk accusing innocent people.
> - If the thief is **really obvious** (big effect size), you’ll catch them easily.
> - Less fog (small standard deviation) helps you see clearly.
> - **One-tailed searches** are easier because you only look in one direction, while two-tailed searches are harder because you’re searching everywhere.

---

# Simple Linear Regression

Simple linear regression is used to model the relationship between a dependent variable $y$ and an independent variable $x$. The goal is to find the best-fitting line through the data points.

> [!Question]
> Find least-squares regression line for the given data:
>
> > We aim to fit $y = mx + c$

## Step 1: Write down the given data

| $x$ | $y$ | $x^2$        | $xy$              |
| --- | --- | ------------ | ----------------- |
| 2   | 0   | $2^2 = 4$    | $2 \cdot 0 = 0$   |
| 2   | 1   | $2^2 = 4$    | $2 \cdot 1 = 2$   |
| 6   | 2   | $6^2 = 36$   | $6 \cdot 2 = 12$  |
| 8   | 3   | $8^2 = 64$   | $8 \cdot 3 = 24$  |
| 10  | 3   | $10^2 = 100$ | $10 \cdot 3 = 30$ |

---

## Step 2: Compute the required sums

$$
\text{Sum of } x: \sum x = 2 + 2 + 6 + 8 + 10 = 28
$$

$$
\text{Sum of } y: \sum y = 0 + 1 + 2 + 3 + 3 = 9
$$

$$
\text{Sum of } x^2: \sum x^2 = 4 + 4 + 36 + 64 + 100 = 208
$$

$$
\text{Sum of } xy: \sum xy = 0 + 2 + 12 + 24 + 30 = 68
$$

$$
\text{Number of points (n)}: n = 5
$$

---

### Step 3: Use the formulas for slope ($m$) and intercept ($c$)

#### Slope ($m$)

> [!Important]
>
> $$
> m = \frac{n \sum xy - \sum x \sum y}{n \sum x^2 - (\sum x)^2}
> $$

Substitute the values:

$$
m = \frac{5(68) - (28)(9)}{5(208) - (28)^2}
$$

$$
m = \frac{88}{256} = 0.34375
$$

#### Intercept ($c$)

$c = \frac{\sum y - m \sum x}{n}$

$c = \frac{9 - (0.34375)(28)}{5}$

$c = -0.125$

---

### Step 4: Write the regression line equation

The least-squares regression line is:

$$
y = 0.34375x - 0.125
$$

---

## Correlation

The correlation coefficient ($r$) quantifies the strength and direction of a linear relationship between two variables. It ranges from -1 to 1.

$$
r = \frac{n(\sum xy) - (\sum x)(\sum y)}{\sqrt{[n\sum x^2 - (\sum x)^2][n\sum y^2 - (\sum y)^2]}}
$$

- $r = 1$: Perfect positive correlation
- $r = -1$: Perfect negative correlation
- $r = 0$: No correlation



## The Least Square Lines

The least squares method **minimizes** the sum of the squared differences between observed values and predicted values.

## Regression Equation

The regression line is given by: $y = b_0 + b_1x$

- $b_1 = \frac{n(\sum xy) - (\sum x)(\sum y)}{n(\sum x^2) - (\sum x)^2}$ (slope)
- $b_0 = \bar{y} - b_1\bar{x}$ (y-intercept)

## Predictions using Regression Models

To make predictions, substitute the value of $x$ into the regression equation. The predicted value $\hat{y}$ is calculated as: $\hat{y} = b_0 + b_1x$

---

## Residual Plots

![[Pasted image 20241124171854.png]]

> Residuals are the differences between the observed values and the predicted values from the regression model. The residual plot helps identify potential issues in the model.

### A. **No noticeable pattern**

- **Plot (a)**: This residual plot shows no clear pattern, which is the ideal scenario. It suggests that the model has successfully captured the relationship between the variables, and the residuals are randomly distributed.
    - **Interpretation**: This means the assumptions of linear regression, such as homoscedasticity (constant variance) and no autocorrelation, are likely satisfied.

### B. **Heteroscedastic**

- **Plot (b)**: This plot shows a pattern where the spread of the residuals increases or decreases as the fitted values change (fan shape).
    - **Interpretation**: The model might not be properly fitting the data. **Heteroscedasticity** means that the variance of residuals is not constant across the range of fitted values, which can lead to inefficiency in the model and unreliable statistical tests. We might need to transform the data or use robust standard errors to correct this issue.

### C. **Trend**

- **Plot (c)**: This plot shows a systematic pattern, with residuals following a curve or trend.
    - **Interpretation**: A **trend** in the residuals suggests that the model might not have captured all the underlying patterns in the data. This could indicate the need for a more complex model (e.g., a non-linear model) or additional variables to improve the fit.

### D. **Outlier**

- **Plot (d)**: This plot shows a distinct point far away from the rest of the residuals.
    - **Interpretation**: This is an **outlier**. The point significantly deviates from the overall pattern of residuals, suggesting it might be an unusual observation. Outliers can affect the regression model, and it’s important to decide whether to remove, investigate, or keep these points in the analysis.

### Summary

- **Plot (a)**: Perfect scenario—no pattern.
- **Plot (b)**: Problem—heteroscedasticity (variance changes).
- **Plot (c)**: Problem—there's a trend, suggesting a better model is needed.
- **Plot (d)**: Problem—outliers that may need further investigation.

Each type of plot helps you understand different potential issues with your regression model, guiding you on whether to make adjustments or try a more complex model.

> [!Example]
> If the vertical spread does not vary with the fitted value, we call the residual plot homoscedastic. Else we call the plot heteroscedastic.

---

![[Pasted image 20241124234939.png]]