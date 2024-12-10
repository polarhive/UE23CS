# Confidence Intervals

## Overview

A confidence interval (CI) provides a range of values that is likely to contain the true parameter of interest. The level of confidence, denoted as $(1 - \alpha)$, represents the proportion of confidence intervals that will contain the true parameter if we were to repeat the study multiple times.

For example, if we have a $(1 - \alpha) = 90\%$ CI, this implies: $\alpha = 10\%$

Consequently, we have: $\frac{\alpha}{2} = 5\%$

### Finding the Critical Value

When seeking the value of $z$ such that the cumulative probability satisfies:

$P(Z < ?) = 0.05$

we are interested in the left tail of the standard normal distribution.

The corresponding $z$-value for this cumulative probability is approximately:

$? = -1.64$ This value indicates that 5% of the data lies to the left of $(-1.64)$.

---

## One-Sided Confidence Intervals

| $\alpha$ | $Z_{\alpha}$ | CI Level |
| -------- | ------------ | -------- |
| 10%      | 1.28         | 90%      |
| 5%       | 1.645        | 95%      |
| 1%       | 2.33         | 99%      |

---

## Two-Sided Confidence Intervals

| $\alpha$ | $Z_{\alpha/2}$ | CI Level |
| -------- | -------------- | -------- |
| 10%      | 1.64           | 90%      |
| 5%       | 1.96           | 95%      |
| 1%       | 2.58           | 99%      |

---

## Confidence Intervals for Proportions

Let $X \sim B(n, p)$, where:

- $np > 10$ (ensures sufficient sample size)
- $np(1-p) > 10$

The sample proportion is calculated as: $\hat{p} = \frac{x}{n}$ where $x$ is the number of successes.

### For a $(1 - \alpha)\%$ confidence interval

- Adjusted sample size:
$\tilde{n} = n + 4$

- Adjusted proportion:
$\tilde{p} = \frac{x + 2}{\tilde{n}} = \frac{x + 2}{n + 4}$

- The confidence interval is then given by:
$p = \hat{p} \pm Z_{\alpha/2} \sqrt{\frac{\tilde{p} (1 - \tilde{p})}{\tilde{n}}}$

---

## Small Sample Confidence Interval for Population Mean

When the sample size $n \leq 30$, and if the population is normally distributed, the $t$-distribution is used to calculate the CI for the population mean:

$$
z = \frac{\bar{x} - \mu}{\frac{\sigma}{\sqrt{n}}}
$$

Where:

- $\sigma$ is the population standard deviation.
- $s$ is the standard deviation of the sample.
- $n$ is the size of the sample.
- $n - 1$ represents the degrees of freedom.

> **Warning**: If a small sample is drawn and the population standard deviation is known, use the Z-score instead of $t_{n-1}$:

$$
z = \frac{\bar{x} - \mu}{\frac{\sigma}{\sqrt{n}}}
$$

### Confidence Interval Formulas

1. General CI formula:
$\text{CI}_{\mu} = \bar{x} \pm t_{n-1, \alpha/2} \left( \frac{s}{\sqrt{n}} \right)$

2. Lower CI limit:
$\text{Lower CI} = \bar{x} - t_{n-1, \alpha/2} \left( \frac{s}{\sqrt{n}} \right)$

3. Upper CI limit:
$\text{Upper CI} = \bar{x} + t_{n-1, \alpha/2} \left( \frac{s}{\sqrt{n}} \right)$

---

## Confidence Interval for the Difference Between Two Means

Consider two samples $x_1, x_2, \ldots, x_n$ and $y_1, y_2, \ldots, y_n$, where:

$X$ and $Y$ are distributed as $\sim \mathcal{N}(\mu_X, \sigma_X^2)$ and $\sim \mathcal{N}(\mu_Y, \sigma_Y^2)$, respectively.

### Distribution of the Difference

The difference $X - Y$ is distributed as:

$X - Y \sim \mathcal{N}(\mu_X - \mu_Y, \sigma^2_X + \sigma^2_Y)$

where:

- $\mu_{X - Y} = \mu_X - \mu_Y$
- $\sigma^2_{X - Y} = \sigma^2_X + \sigma^2_Y$

### Confidence Interval Level

The confidence interval for the difference between the two means is given by:

$$
\bar{X} - \bar{Y} \pm Z_{\alpha/2} \sqrt{\frac{\sigma_X^2}{n_X} + \frac{\sigma_Y^2}{n_Y}}
$$

---

## Confidence Interval for Paired Data (n ≤ 30)

The confidence interval for the mean difference $\mu_D$ is given by:

$$
\mu_D = \bar{D} \pm t_{n-1, \alpha/2} \cdot \frac{S_D}{\sqrt{n}}
$$

---

## Factors Affecting Margin of Error (MoE)

The margin of error is calculated as:

$$
\text{MoE} = Z_{\alpha/2} \cdot \frac{\sigma}{\sqrt{n}}
$$

### To Reduce MoE

- Increase $(1 - \alpha)$
- Decrease $\sigma$
- Increase $n$

---

# Hypothesis Testing

## Introduction

Hypothesis testing is a statistical method used to make decisions based on data analysis. It involves formulating two competing hypotheses: the null hypothesis $H_0$ and the alternative hypothesis $H_1$. The aim is to assess the strength of the evidence against the null hypothesis using sample data.

## Hypotheses

- **Null Hypothesis $H_0$**: This hypothesis states that there is no effect or no difference, serving as the default assumption. For example, it could assert that the means of two populations are equal.
- **Alternative Hypothesis $H_1$**: This hypothesis represents what we aim to prove, suggesting that there is an effect or a difference. For instance, it might claim that the means of two populations are not equal.

### Critical Values

Critical values are thresholds that define the boundaries of the acceptance and rejection regions for the null hypothesis. In a standard normal distribution:

- The critical value $Z_c$ corresponds to the upper threshold.
- The critical value $-Z_c$ corresponds to the lower threshold.

### Acceptance and Rejection Regions

- **Acceptance Region**: This is the range of values for which we do not reject the null hypothesis, bounded by the critical values.
- **Rejection Region**: This is the range of values for which we reject the null hypothesis. If the test statistic falls within this region, it indicates that the observed data is inconsistent with $H_0$.

### Decision Rule

The decision rule is based on comparing the p-value with a predetermined significance level $\alpha$, typically set at $0.05$:

- If the p-value is less than $0.05$:
  - **Reject $H_0$**: There is sufficient evidence to support the alternative hypothesis.
- If the p-value is greater than or equal to $0.05$:
  - **Accept $H_0$**: There is not enough evidence to reject the null hypothesis.

### p-value Calculation

The p-value quantifies the probability of obtaining a test statistic as extreme as, or more extreme than, the observed value under the assumption that $H_0$ is true. It is calculated as:

$\text{p-value} = P(\text{right}) + P(\text{left})$

This means the p-value is the sum of the probabilities in both tails of the distribution, depending on whether the test is one-tailed or two-tailed.

---

# Statistical Concepts: p-Value, Statistical Significance, Interpolation, and Extrapolation

## p-Value and Statistical Significance

The p-value is a critical concept in hypothesis testing. It quantifies the probability of observing a test statistic at least as extreme as the one obtained, assuming the null hypothesis $H_0$ is true. A smaller p-value indicates stronger evidence against the null hypothesis.

> **Statistical Significance**: A result is considered statistically significant if the p-value is less than or equal to a predetermined significance level $\alpha$ (commonly set at 0.05). In such cases, researchers reject the null hypothesis, suggesting that the observed effect is unlikely to be due to random chance.

### Interpretation of p-Values

- $p < 0.01$: Strong evidence against $H_0$, indicating a significant effect.
- $0.01 < p < 0.05$: Moderate evidence against $H_0$; results are significant but require cautious interpretation.
- $p \geq 0.05$: Insufficient evidence to reject $H_0$; the results may be attributed to chance.

---

## Interpolation

Interpolation is the method of estimating unknown values that fall within the range of known data points. It is widely used in statistics, mathematics, and various fields to fill gaps in data. For instance, if we have temperature readings at 10 AM and 12 PM, we can interpolate to estimate the temperature at 11 AM.

## Extrapolation

Extrapolation is the process of estimating unknown values outside the range of known data points. While it can provide insights into trends and future behavior, it carries greater risk than interpolation, as it assumes that the established relationship continues beyond the observed data.