# Unit 1: Introduction, Performance Metrics, Classification (Decision Trees, Logistic Regression, KNN)

## Introduction to Machine Learning

### 1.1 Definition and the Learning Task

Machine Learning (ML) is fundamentally defined by **Tom Mitchell** as the study of algorithms that **improve their performance (P)** at some **task (T)** with **experience (E)**. Experience (E) is equivalent to the training data. A well-defined learning task is given by the triplet: **`<P, T, E>`**.

Examples of defining ML problems using `<P, T, E>` include:

- Learning to play Checkers Game.
- Handwriting Recognition Learning Problem.
- Self-driven cars (Robot driving problem).
- Learning to Check for spam.
- Learning to detect Credit Card Fraud.

### 1.2 The Machine Learning Flow: 7 Steps

The process of applying an ML algorithm follows a structured flow:

1. **Data Collection**.
2. **Data Preparation**.
3. **Choosing a model**.
4. **Training**.
5. **Evaluation**.
6. **Parameter Tuning**.
7. **Prediction**.

## Machine Learning Models and Paradigms

### 2.1 Supervised Learning

In supervised learning, models are trained using a labeled dataset, meaning the training data comes with **desired outputs (labels)**. The goal is to learn a mapping function $Y = f(X)$ to approximate the relationship between input variables ($x$) and an output variable ($Y$). This function approximation is also called a **hypothesis function**, meaning an approximation or claim.

| Type               | Output Variable (Y)                     | Example                           | Algorithms                                                   |
| :----------------- | :-------------------------------------- | :-------------------------------- | :----------------------------------------------------------- |
| **Classification** | **Categorical** (e.g., discrete labels) | Type of Tumor/Cancer, Spam filter | Decision Trees, Logistic Regression, Support Vector Machines |
| **Regression**     | **Continuous** (real-valued)            | House price prediction            | Linear Regression, Bayesian Linear Regression                |

### 2.2 Unsupervised Learning (Exploratory Learning)

Unsupervised learning is also called **Exploratory Learning**. Models are trained using **unlabelled datasets** and are allowed to act on that data without any supervision.

- **Goal:** To find the **underlying structure** of the dataset, group data according to similarities, and represent the dataset in a compressed format.
- **Clustering:** Grouping objects into clusters where objects within a group share the most similarities and have less or no similarities with objects of another group. (E.g., Customer Segmentation, Anomaly detection).
- **Association:** Finding the relationships between variables in a large database, determining the set of items that occur together (e.g., Market Basket Analysis).

### 2.3 Reinforcement Learning (RL)

RL involves an algorithm (**agent**) learning what actions to take (map situations to actions) by interacting with an **environment**.

- **Feedback Mechanism:** The agent receives **positive feedback (reward)** or **negative feedback (punishment)** after each action.
- **Goal:** The learner must discover which action will yield the **maximum cumulative reward**. The policy the agent learns is called the **control policy**.
- **Key Elements of RL:**
    - **Agent:** Software programs that make intelligent decisions and are the learners.
    - **Policy Function:** Defines the agent's behavior and dictates which action to perform based on received rewards/penalties.
    - **Value Function:** Denotes how good it is for an agent to be in a particular state ($v(s)$), equal to the total expected reward received starting from that state.
- **Applications:** Building AI for playing computer games (e.g., AlphaGo Zero), Robotics, Text mining (producing summaries), Trade execution, and Healthcare (e.g., medication dosing).

### 2.4 Generative vs. Discriminative Models

Machine learning models can be classified into these two types.

- **Discriminative Model:** Makes predictions based on conditional probability (e.g., $P(y|x)$) and is used for classification or regression. Discriminative models **draw boundaries** in the data space.
    - _Examples:_ Logistic regression, Decision Tree, Random Forest, Support Vector Machine.
- **Generative Model:** Revolves around the distribution of a dataset (e.g., $P(x,y)$) to return a probability for a given example. Generative models **model how data is placed throughout the space**.
    - _Examples:_ Bayesian Network, Hidden Markov Model, Generative Adversarial Network (GANs).

## Concept Learning

Concept learning is defined as "the problem of searching through a predefined space of potential hypotheses for the hypothesis that best fits the training examples".

### 3.1 Feature Space and Concept Space

- **Feature Space ($\chi$):** The set of all possible combinations of attributes (features) used to describe examples. For example, if a fruit has two binary features (Color: Red/Green, Shape: Round/Long), the size of the feature space is $2^2 = 4$.
- **Concept Space:** The set of all possible concepts that can be formed using the feature space. It includes every possible labeling (positive/negative) of every feature vector. If there are $d$ binary features, the number of possible examples is $m = 2^d$, and the total number of possible concepts is immense: $\mathbf{2^m = 2^{(2^d)}}$.

### 3.2 Hypothesis Space and Inductive Bias

To make learning feasible, assumptions must be made about the nature of the concept, which significantly **reduces the overall concept space**.

- **Inductive Bias:** This assumption about the nature of the concept is called the **inductive bias**.
    - If the bias restricts the hypothesis to only **conjunctive concepts** (e.g., conjunction of attribute values), it is called a **Restriction Bias**.
    - By applying a restriction bias, the concept space (e.g., $2^{96}$ for a 6-attribute problem) can be dramatically reduced to a smaller, manageable hypothesis space $H$ (e.g., 973 semantically distinct hypotheses).
- **Hypothesis Space ($H$):** The **shrunken space** resulting from the inductive bias. The target concept may or may not be present in $H$.

### 3.3 Version Space (VS)

- The **Version space (VS)** is the subset of the hypothesis space ($H$) consisting of **all hypotheses that are consistent with the training data** ($D_{training}$).
- A hypothesis ($h$) is **consistent** with the training dataset if it classifies all objects in the training data set to their corresponding correct classes ($h(x_i)=C(x_i)$).

### 3.4 Find-S Algorithm

The **Find-S algorithm** is a basic concept learning algorithm.

- **Functionality:** It finds the **most specific hypothesis** within $H$ that fits all the **positive training examples**.
- **Search Strategy:** It moves from the most specific hypothesis (initialized to $h = \emptyset$) to the most general hypothesis. It ignores negative instances.
- **Limitation:** The output hypothesis is just **one of many hypotheses** that might fit the training data equally well. It is consistent with negative examples only if the correct target concept is in $H$ and there are no errors in the training examples. Inconsistent training sets can mislead Find-S since it ignores negative examples.

## Performance Metrics

Metrics are essential to measure the effectiveness of a model using the model and test data sets.

### 4.1 Confusion Matrix

The confusion matrix is a specific table layout that allows visualization of a classifier's performance.

|Term|Definition|Outcome|
|:--|:--|:--|
|**True Positive (TP)**|Instance is positive and is classified as positive.|Correct Prediction (Positive)|
|**True Negative (TN)**|Instance is negative and is classified as negative.|Correct Prediction (Negative)|
|**False Negative (FN)**|Instance is positive but is classified as negative.|Wrong Prediction|
|**False Positive (FP)**|Instance is negative but is classified as positive.|Wrong Prediction|

### 4.2 Key Classification Metrics

|Metric|Calculation|Interpretation & Use Case|
|:--|:--|:--|
|**Accuracy**|$(TP + TN) / Total$|Good measure when classes are nearly balanced, but poor if the dataset is imbalanced (**Class Skew**).|
|**Precision**|$TP / (TP + FP)$|Measures how many correct positive cases were caught. Useful when the cost of **false positives (FP)** is significantly higher (e.g., Spam detection, Product recommendations).|
|**Recall (Sensitivity/TPR)**|$TP / (TP + FN)$|Measures how many of the actual positive cases were caught correctly. Useful when the cost of a **false negative (FN)** is very high (e.g., Medical diagnoses, Fraud detection).|
|**Specificity (TNR)**|$TN / (TN + FP)$|Measures how many negative cases were caught correctly.|
|**F1 Score**|$2 \times (Recall \times Precision) / (Recall + Precision)$|The **harmonic mean** of precision and recall. It reaches its optimum (1) only if both precision and recall are 100%.|

### 4.3 ROC and AUC

- **ROC (Receiver Operating Characteristics):** A probability curve that plots the **True Positive Rate (TPR)** against the **False Positive Rate (FPR)** at various threshold values.
    - A point at **(0, 1)** represents a perfect classification.
    - The diagonal line ($y=x$) represents randomly guessing a class.
    - **Conservative classifiers** (preference for strong evidence before classifying positive) tend to have lower TPR and lower FPR.
    - **Liberal classifiers** (tendency to classify more as positive) exhibit higher TPR and higher FPR.
- **AUC (Area Under the ROC Curve):** Defines how good the model is; a higher AUC suggests better performance at **distinguishing between the positive and negative classes**.
    - AUC = 1: Perfect distinction.
    - AUC = 0.5: Classifier performs no better than random guessing.
    - AUC = 0: Classifier predicts all negatives as positives, and vice versa.

## Bias-Variance Decomposition

The **total expected prediction error** can be decomposed into two parts: **Irreducible Error** and **Reducible Error** (Bias and Variance).

- **Irreducible Error ($\sigma^2$):** The error caused by **inherent noise** in the data. It cannot be fixed and exists even in the best models.
- **Reducible Error:** Comprises bias and variance, and represents the error that the model can potentially minimize.

|Component|Definition|Effect on Training Error|Classification Problem Scenario|
|:--|:--|:--|:--|
|**Bias**|Systematic error due to overly simple model assumptions.|**High Bias** $\implies$ **Underfitting** (Model fails to capture data pattern; high training error).|Linear classifier unable to fit a quadratic shape.|
|**Variance**|Fluctuation in predictions when trained on different datasets.|**High Variance** $\implies$ **Overfitting** (Model captures noise; low training error but high test error).|Highly complex boundary that perfectly separates training points but fails on new data.|

- **Bias-Variance Tradeoff:** As model complexity increases, **bias decreases** initially, while **variance increases**. The total error decreases until the point where the increase in variance outweighs the reduction in bias. The point where the total error is minimized is the **optimal model complexity**.

## Decision Trees

Decision Trees are flowchart-like diagrams used to make decisions based on a series of conditions. They can be used for both classification and regression problems.

### 6.1 Structure and Representation

- **Node:** Specifies an attribute to be tested.
- **Branch:** Corresponds to one of the possible values for an attribute.
- **Leaf Node:** The end of the decision tree, carrying the classification label.
- **Decision Trees represent a disjunction of conjunctions** (e.g., (Outlook = Sunny $\land$ Humidity = Normal) $\lor$ (Outlook = Overcast) $\lor$ ...).

### 6.2 ID3 Algorithm (Classification)

The ID3 algorithm creates a multiway tree by greedily selecting the categorical feature that yields the largest information gain for the targets.

- **Entropy:** An indicator of **non-homogeneity / uncertainty / disorder** that needs to be reduced. Higher entropy means the dataset is more non-homogeneous.

$$
\text{Entropy}(A) = H(A) = - \sum_{i=1}^{c} p(x_i) \log_2 (p(x_i))
$$

- **Information Gain:** The expected **reduction in entropy** caused by partitioning the examples according to an attribute. The attribute with the **maximum Gain** is picked as the decision node.

$$
\text{Information Gain} = (\text{Entropy before split} – \text{Entropy after split})
$$

### 6.3 Hypothesis Space and Inductive Bias

- **Hypothesis Space:** The set of all possible decision trees.
- **Search Strategy:** ID3 performs a **simple-to-complex, informed search** using gain as a greedy heuristic. It is a statistically-based search that looks at the set of all instances under a branch (unlike Find-S). The greedy search means it does not guarantee an optimal solution and performs an incomplete search.
- **Inductive Bias (Preference Bias):** ID3 favors the **shortest trees** (Occam’s razor) and attributes with the **highest gain** closest to the root. It also favors attributes with many values as they are more likely to lead to reduced entropy and thus increased gain.

### 6.4 Issues and Solutions (Overfitting)

- **Overfitting:** A critical issue where the tree becomes **too specific to the training set**, capturing noise, which leads to poor performance on new/test instances.
    - _Formal Definition:_ Hypothesis $h$ overfits if there exists an alternative $h'$ such that $h$ has smaller error than $h'$ over the training examples, but $h'$ has a smaller error than $h$ over the entire distribution of instances.
- **Solution: Pruning**
    - Pruning involves cutting off the tree at some point to make it more general.
    - **Early Termination (Pre-Pruning):** Stopping the tree's growth earlier (e.g., halting if gain falls below a threshold or setting a maximum depth).
    - **Post Pruning:** Allowing the tree to fully overfit, then selectively modifying it later, often found to be more effective. Requires partitioning data into **training**, **validation** (for pruning), and **test** sets.
        - **Reduced Error Pruning:** Iteratively replace a decision node with its most popular class if the prediction accuracy is unaffected or improves over the **validation set**.
        - **Rule Post-Pruning:** Convert the tree into an equivalent set of rules, and then prune preconditions from these rules that do not worsen the estimated accuracy.

### 6.5 Dealing with Continuous Values

ID3's initial restriction to discrete values can be lifted by defining a new **Boolean attribute, $A_c$** (true if $A < c$, false otherwise) based on a continuous attribute $A$ and a threshold $c$.

- **Optimal Threshold Selection:** Sort the examples by attribute $A$. Candidate thresholds are selected **midway between adjacent examples that differ in their target classification**, aiming to maximize information gain.

## Logistic Regression

Logistic Regression is an algorithm primarily used for **classification problems** developed to ensure that the output/predictions are contained within the range of **0 to 1**.

- **Hypothesis Function:** Uses the **sigmoid (logistic) function** applied to the linear regression output to contain the prediction $h_\theta(x)$ between 0 and 1.
- **Interpretation:** $h_\theta(x)$ is the **estimated probability that $y=1$ on input $x$** ($P(y=1 | x; \theta)$). If $h_\theta(x) = 0.7$, there is a 70% chance that $y=1$.
- **Decision Boundary:** The boundary is where the linear term equals zero. By adding **higher-order polynomial terms** (e.g., $x_1^2, x_2^2$), logistic regression can fit **complex non-linear decision boundaries** (e.g., a circle).
- **Cost Function:** The standard squared error used in linear regression results in a non-convex function for logistic regression, potentially trapping gradient descent in local minima. A specific cost function is used that penalizes the algorithm with a **massive cost ($\infty$)** if it predicts $P(y=1)=0$ but the true value is $y=1$.
- **Multi-Class Classification (One-vs-All):** To handle multi-class problems (e.g., $y \in {1, 2, 3...}$), a logistic regression classifier $h_\theta^{(i)}(x)$ is trained for **each class $i$** to predict the probability that $y=i$. The final prediction picks the class $i$ that maximizes $h_\theta^{(i)}(x)$.

## Instance-based learning: k-nearest neighbor (KNN)

KNN is an **instance-based learning** algorithm (also called **lazy learning** or memory-based learning). It **postpones computation** until a new instance is observed, relying on stored training data.

### 8.1 Core Mechanism and Bias

- **Inductive Bias:** The assumption that the classification of a new instance ($x$) will be **most similar to the classification of the $K$ other instances that are nearby**.
- **Distance Measures:** Neighbors are identified using distances like **Manhattan distance** ($q=1$) or **Euclidean distance** ($q=2$).
- **Classification & Regression:**
    - For **classification** (discrete target variable), the prediction is the **mode** (majority vote) of the $K$ neighbors' classes.
    - For **regression** (real target variable), the prediction is the **mean value** of the $K$ nearest neighbors.
- **Weighted KNN:** Allows for greater influence of closer neighbors by weighting the contribution of each neighbor **inversely according to their distance** to the query point.

### 8.2 Bias-Variance Tradeoff in KNN

The choice of $K$ significantly impacts the model performance:

- **Very Low $K$** (e.g., $K=1$): High **variance**. The model is highly sensitive to small shifts in data, resulting in **overfitting**.
- **Very High $K$**: High **bias**. The prediction tends to align with the majority class of the entire dataset, resulting in **underfitting**.
- **K Selection:** In practice, there is no single right value for $K$. Suggestions include starting with $K = \text{number of classes} + 1$, or using $K = \sqrt{n}$ (where $n$ is dataset size). The **Elbow Method** involves calculating the error rate for different $K$ values and choosing the point where the error reduction plateaus.

### 8.3 Practical Challenges

- **Feature Scaling:** KNN is **sensitive to scaling**. Variables with high magnitudes (like income) can disproportionately influence distance calculation compared to low-magnitude variables (like age). **Normalization** is required to ensure similar weightage is given to all variables.
- **Curse of Dimensionality:** In high-dimensional spaces, points become extremely sparse, and distances between points concentrate within a very small range. This breaks the assumption that nearest neighbors are actually more similar than random data points, degrading the classifier's performance. Techniques to mitigate this include **dimensionality reduction** (e.g., PCA) or assigning weights to attributes.
