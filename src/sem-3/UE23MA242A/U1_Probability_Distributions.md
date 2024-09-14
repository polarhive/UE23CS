# Applications of Probability Distributions and Principles of Point Estimation

> _Statistics is concerned with developing and studying different methods for collecting, analyzing and presenting the empirical data._

Data science is an interdisciplinary field based on scientific methods, processes algorithms, and systems to extract knowledge and insights from the structured and unstructured data. Data science is basically analyzed on mathematical and statistical techniques.

## Types of statistics

### Descriptive

Applied on finite numerical data

> Measures of central tendency

- mean
- median
- mode

> Measures of variability

- range
- variance
- dispersion

### Inferential

Applied on a population, or a sub-set of a population called a **sample**. A sample is finite numerical data, hence descriptive statistics is applied on this sample. It is required to draw conclusions about the populations based on the characteristics of the sample.

---

# Types of Data

| Primary Data                               | Secondary Data                                              |
| ------------------------------------------ | ----------------------------------------------------------- |
| Raw data obtained directly from the source | Collected through someone else, rather than the actual user |
| By experiments, surveys and observation    | By magazines, newspapers, books and journals                |

## Types of primary data

- **Quantitative**:
  - Discrete: $\{ -\infty, -2, -1, 0, \ldots, 2 \}$
  - Continuous:
    - Interval: Zero has no significance <- Indicates an absence of a variable you're measuring.
    - Ratio: Zero and above $[0 \rightarrow \infty]$
- **Qualitative** (Non-numerical):
  - Nominal: Key-based adjectives
  - Ordinal: Key-ordered by ascending/descending

---

# Experiments

## Controlled

First define all the variables:

X: Independent variable
Y: Dependent f(X)
${ \Sigma}$: Extraneous variables (influence the dependent variables)

## Observational

---

# Types of population

**Population:** The set of all objects under our study is called population or universal set. The objective of inferential statistics is to draw the conclusions about the population by analyzing the sample.

1. Finite population: students in a college
2. Infinite population: stars in the sky
3. Existent population: books, students
4. Hypothetical population: sets of observations -- by tossing a coin or a die
5. Tangible population: physical objects in the real world (finite, countable)
6. Conceptual population: do not consist of physical objects (reading on a scale)

#### Sampling Frame

From where the sample is drawn. The actual list of individuals the sample will be drawn from.

#### Sample size

The number of objects in a sample

---

# Sampling methods

## Probabilistic

There's a chance for every member to be in the sample. This technique is used in qualitative research.

1. **Simple Random** (RNG): each individual of the population has an equal chance being selected
2. **Systematic** (Imposing a condition): like simple random sampling, but individuals are selected at equal intervals
3. **Stratified**: The entire populations is divided into sub-populations which are more homogeneous than the total populations, these sub populations are called strata then a sample is obtained by taking elements from each strata. $$n_i = \frac{n N_i \sigma_i}{N_1 \sigma_1 + N_2 \sigma_2 + \cdots + N_n \sigma_n}$$where ${( n_i )}$ is the optimum allocation.

4. **Clusters**: (No homogeneity) population is divided into finite number of distinct and identifiable units caled sampling units. The groups of the population are called clusters, then a sample is the elements of n-clusters.  

## Non-Probabilistic

This technique is used in qualitative research

1. **Snowball**: viral
2. Convenience
3. Quota
4. Judgmental

### Sampling Errors

### Chebyshev's inequality?

### Normal Probability Plots

## Introduction to Generation of Random Variates

mention the types, Acceptance-Rejection method, Sampling Distribution, The Central Limit Theorem and Applications, Principles of Point Estimation - Mean Squared Error for Bernoulli, Binomial, Poisson, Normal, Maximum Likelihood Estimate for Bernoulli, Binomial, Poisson, Normal and Case Study. Introduction to multivariate normal distribution, MAP distribution
