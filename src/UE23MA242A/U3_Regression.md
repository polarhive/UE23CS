# Linear Regression and Distribution Free Tests

### Chi-squared Test

The Chi-squared test is a non-parametric test used to determine if there is a significant association between categorical variables. It compares the observed frequencies in each category to the frequencies we would expect if there were no association.

The ***test statistic*** is calculated as:

$$\chi^2 = \sum \frac{(O_i - E_i)^2}{E_i}$$
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

- **Type I Error ($\alpha$)**: The probability of rejecting the null hypothesis when it is true. For example, concluding that a new drug is effective when it is not.
- **Type II Error ($\beta$)**: The probability of failing to reject the null hypothesis when it is false. For example, concluding that a new drug is not effective when it actually is.

### Power of a Test

The power of a test is the probability of correctly rejecting the null hypothesis when it is false. It is influenced by several factors: 

$\text{Power} = 1 - \beta$

### Factors Affecting Power

1. **Sample Size (n)**: Increasing the sample size reduces variability and increases power.
2. **Effect Size**: Larger effect sizes (the difference between the null hypothesis and the true value) increase power.
3. **Significance Level ($\alpha$)**: Increasing $\alpha$ increases power but also increases the risk of Type I error.

---
# Simple Linear Regression

Simple linear regression is used to model the relationship between a dependent variable $y$ and an independent variable $x$. The goal is to find the best-fitting line through the data points.
### Correlation

The correlation coefficient ($r$) quantifies the strength and direction of a linear relationship between two variables. It ranges from -1 to 1.

$$r = \frac{n(\sum xy) - (\sum x)(\sum y)}{\sqrt{[n\sum x^2 - (\sum x)^2][n\sum y^2 - (\sum y)^2]}}$$

- $r = 1$: Perfect positive correlation
- $r = -1$: Perfect negative correlation
- $r = 0$: No correlation

### The Least Square Lines

The least squares method minimizes the sum of the squared differences between observed values and predicted values.

### Regression Equation

The regression line is given by: $y = b_0 + b_1x$

- $b_1 = \frac{n(\sum xy) - (\sum x)(\sum y)}{n(\sum x^2) - (\sum x)^2}$ (slope)
- $b_0 = \bar{y} - b_1\bar{x}$ (y-intercept)

### Predictions using Regression Models

To make predictions, substitute the value of $x$ into the regression equation. The predicted value $\hat{y}$ is calculated as: $\hat{y} = b_0 + b_1x$

---
