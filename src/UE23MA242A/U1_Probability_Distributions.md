# Applications of Probability Distributions and Principles of Point Estimation

> _Statistics is the discipline that involves developing methods for collecting, analyzing, interpreting, and presenting empirical data._

Data science is an interdisciplinary field that leverages scientific methods, processes, algorithms, and systems to extract meaningful insights from structured and unstructured data. Statistical and mathematical techniques form the foundation for data analysis in this field.

# Types of Statistics

## Descriptive Statistics

Descriptive statistics summarize and describe the characteristics of a data set. These methods are applied to finite numerical data, providing insights into the data's central tendency and variability.

> **Measures of Central Tendency** represent the typical value in a data set:

- **Mean**: The arithmetic average of the data set.
- **Median**: The middle value when the data is ordered.
- **Mode**: The most frequently occurring value.

> **Measures of Variability** describe the spread or dispersion of the data:

- **Range**: The difference between the maximum and minimum values.
- **Variance**: The average of the squared differences from the mean.
- **Standard Deviation**: The square root of the variance, providing a measure of spread in the same units as the data.

## When to Use Mean, Median, and Mode?

The choice of which measure of central tendency to use depends on the type and distribution of the data:

| Type of Variable            | Best Measure of Central Tendency |
| --------------------------- | -------------------------------- |
| **Nominal**                 | Mode                             |
| **Ordinal**                 | Median                           |
| **Interval/Ratio (Not Skewed)** | Mean                          |
| **Interval/Ratio (Skewed)**  | Median                           |

## Inferential Statistics

Inferential statistics allow us to make generalizations or predictions about a population based on the analysis of a **sample**, which is a subset of the population. Since samples are finite, descriptive statistics are applied to the sample. The goal is to use the sample's characteristics to infer the properties of the entire population.

---

# Types of Data

Data can be classified into two broad categories:

| **Primary Data**                               | **Secondary Data**                                               |
| ---------------------------------------------- | ---------------------------------------------------------------- |
| Data collected firsthand directly from the source | Data gathered from existing sources (e.g., reports, publications) |
| Collected through experiments, surveys, or observation | Retrieved from books, journals, or media                           |

## Types of Primary Data

Primary data can be further categorized as:

- **Quantitative**: Data that can be expressed numerically.
  - **Discrete**: Countable values (e.g., $0, 1, 2, \dots$).
  - **Continuous**:
    - **Interval**: Measurements where the zero point is arbitrary (e.g., temperature in Celsius).
    - **Ratio**: Measurements with an absolute zero, allowing for meaningful comparisons (e.g., height, weight).
- **Qualitative**: Categorical data that cannot be expressed numerically.
  - **Nominal**: Categories with no inherent order (e.g., colors, names).
  - **Ordinal**: Ordered categories (e.g., rankings, levels of satisfaction).

---

# Experiments

## Controlled Experiments

Controlled experiments manipulate one or more independent variables to observe their effect on a dependent variable, while controlling for extraneous variables. The structure is typically represented as:

- **X**: Independent variable (manipulated by the experimenter)
- **Y**: Dependent variable (the outcome measured as a function of X)
- **Σ**: Extraneous variables (variables that could affect Y but are not the focus of the study)

## Observational Studies

In observational studies, researchers observe subjects in a natural setting without manipulation, often used when controlled experiments are impractical or unethical.

---

# Types of Populations

In statistical analysis, the **population** refers to the entire set of individuals or items under investigation. The primary aim of inferential statistics is to draw conclusions about a population by analyzing a sample.

1. **Finite Population**: A countable number of items (e.g., students in a school).
2. **Infinite Population**: An uncountable number of items (e.g., stars in the universe).
3. **Existent Population**: Populations that exist physically (e.g., books, students).
4. **Hypothetical Population**: Populations of potential outcomes (e.g., results of repeated coin tosses).
5. **Tangible Population**: Physical objects that are countable and finite.
6. **Conceptual Population**: Non-physical entities or abstract measurements (e.g., repeated measurements on a scale).

## Sampling Frame

The **sampling frame** is the actual list from which the sample is drawn, ideally representing the entire population.

## Sample Size

The **sample size** is the number of individuals or observations included in the sample, which plays a critical role in the reliability of the statistical inference.

---

# Sampling Methods

## Probabilistic Sampling

In probabilistic sampling, every member of the population has a known, non-zero chance of being selected, making it suitable for quantitative research.

1. **Simple Random Sampling**: Every individual has an equal chance of being selected.
2. **Systematic Sampling**: Individuals are selected at regular intervals from an ordered list.
3. **Stratified Sampling**: The population is divided into homogeneous subgroups (strata), and samples are drawn from each subgroup. Optimal allocation is given by:

$$
n_i = \frac{n N_i \sigma_i}{N_1 \sigma_1 + N_2 \sigma_2 + \cdots + N_n \sigma_n}
$$

4. **Cluster Sampling**: The population is divided into groups (clusters), and a random sample of entire clusters is selected.

### Non-Probabilistic Sampling

Non-probabilistic sampling methods do not give every individual a chance of being included, often used in qualitative research.

1. **Snowball Sampling**: Participants refer other participants, often used in hard-to-reach populations.
2. **Convenience Sampling**: The sample is drawn from an easily accessible group.
3. **Quota Sampling**: Participants are selected to meet predefined quotas.
4. **Judgmental Sampling**: The researcher selects participants based on subjective judgment.

### Sampling Errors

Sampling errors arise when a sample does not adequately represent the population, leading to inaccurate inferences.

---

## Chebyshev's Inequality

Chebyshev's inequality provides a bound on how much data lies within a certain number of standard deviations from the mean, regardless of the distribution.

## Normal Probability Plots

Normal probability plots visually assess whether data follow a normal distribution by plotting observed values against expected normal values.

---

# Random Variate Generation

Self learning

## Types of Random Variates

Random variates are numbers generated from a specific probability distribution, used in simulations and statistical models.

## Acceptance-Rejection Method

The acceptance-rejection method is a technique for generating random numbers from a complex probability distribution by using a simpler distribution as an intermediary.

---

# Sampling Distribution and the Central Limit Theorem

The **Central Limit Theorem** states that, given a sufficiently large sample size, the sampling distribution of the sample mean will approach a normal distribution, regardless of the original distribution of the data.

---

# Principles of Point Estimation

Point estimation involves estimating a population parameter using sample data. Key principles include minimizing **Mean Squared Error (MSE)** and applying methods like **Maximum Likelihood Estimation (MLE)**.

## Mean Squared Error (MSE) for Common Distributions

MSE is a measure of the average squared difference between the estimator and the true parameter. It is commonly used for distributions such as:

- Bernoulli
- Binomial
- Poisson
- Normal

## Maximum Likelihood Estimation (MLE)

MLE is a method of estimating the parameters of a probability distribution by maximizing the likelihood function, making it suitable for Bernoulli, Binomial, Poisson, and Normal distributions.

---

# Multivariate Normal Distribution

The multivariate normal distribution generalizes the normal distribution to multiple dimensions, used when dealing with vector-valued random variables.

# MAP Estimation

Maximum A Posteriori (MAP) estimation is a Bayesian approach that finds the mode of the posterior distribution, incorporating prior knowledge into the estimation process.
