# Unit 2 - Artificial Neural Networks (ANN), Support Vector Machines (SVM), Boosting

## Artificial Neural Networks (ANN)

### Introduction

The **Artificial Neural Network (ANN)** is fundamentally built upon the **artificial neuron** or simply **neuron**. The concept and structure of ANNs are inspired by **biological neurons** found in the brain, mimicking how they pass signals.

A typical ANN structure includes the **input layer**, one or more **hidden layers**, and an **output layer**. If a network contains more than one hidden layer, it is termed a **Deep ANN (DNN)**. A fully connected multi-layer network is known as a **Multilayer Perceptron (MLP)**.

Key parts of a biological neuron and their artificial counterparts:

- **Dendrite:** Obtains information (input).
- **Soma:** Processing center.
- **Axon:** Carries nerve impulses away (output).
- **Synapse:** Point of connection/communication between neurons.

Early models included the **McCulloch Pitts (MP) neuron**, which proposed a highly simplified computational model using thresholding logic. The MP neuron aggregates inputs and takes a decision based on this aggregation.

### Perceptrons

The classical **Perceptron** model was proposed by Frank Rosenblatt in 1958. It is a more general computational model compared to MP neurons.

Primary differences from the MP neuron:

1. **Introduction of numerical weights** for inputs and a mechanism for learning these weights and the bias.
2. Inputs are **no longer limited to Boolean values**.

The perceptron output is defined based on a weighted sum of inputs:

$$
y = 1 \text{ if } W^T x + b \ge 0
$$

$$
y = 0 \text{ if } W^T x + b < 0
$$

A single perceptron implements a **linear decision surface**, meaning it can represent simple Boolean functions that are linearly separable, such as AND, OR, NAND, and NOR.

The perceptron fails if the data is **not linearly separable**, such as the **XOR function**.

### Multi-layer networks and Back-propagation

Because a single neuron cannot learn complex functions, artificial neurons are arranged in layers, forming a network. This setup allows information to be passed from one layer to the next.

Layers in a typical ANN/MLP:

- **Input Layer:** Where inputs are fed; no computation is performed here.
- **Hidden Layer(s):** The core for learning and processing; responsible for deriving complex relationships and identifying patterns.
- **Output Layer:** Emits the final output after processing.

**Back-propagation** (Backward propagation) is the process used to modify the parameters (weights, bias) with the objective of minimizing the loss or error in the predicted value. For each training example, weights are modified to minimize the loss function between the network's prediction and the actual target value.

The weight modifications are done in the "backward" direction—from the output layer, through each hidden layer, down to the first hidden layer. Weights are updated using the **gradient descent** method.

A significant challenge during back-propagation, especially with functions like Sigmoid, is the **vanishing gradients problem**. As the backpropagation algorithm moves backward, gradients approach zero, leaving the weights of the initial/lower layers nearly unchanged, preventing convergence to the optimum.

Another issue is **overfitting**, where weights are tuned to fit the noise of the training examples. Solutions to avoid overfitting in neural networks include:

- Using a separate **validation set** and choosing the weights that produce the least error on it.
- **Dropout:** Randomly dropping neurons during training (a regularization technique).
- **Early termination:** Stopping the training process before the model begins to overfit the training data.

### Activation functions (Step, Sigmoid, Tanh, ReLU)

Activation functions introduce **non-linearity** into the network. Without them, the network would only perform linear transformations, making it equivalent to a linear regression model and unable to learn complex patterns.

|Function|Range|Key Characteristics|Usage Notes|
|:--|:--|:--|:--|
|**Sigmoid**||Differentiable. Often used where the output is interpreted as a **probability**.|Popular in networks with 1 hidden layer.|
|**Tanh** (Hyperbolic Tangent)|[-1, 1]|Differentiable. Maps negative inputs strongly negative and zero inputs near zero.|Mainly used for binary classification. Considered better than Sigmoid.|
|**ReLU** (Rectified Linear Unit)|[0, $\infty$)|$f(x) = x$ when $x > 0$; $0$ when $x \le 0$.|Widely used in deep neural networks. Suffers from **Dying ReLU**, where negative inputs turn immediately to zero, hindering training.|
|**Leaky ReLU**|$[-\infty, \infty)$|Addresses Dying ReLU: $f(y) = y$ when $y > 0$; $ay$ when $y \le 0$ (where $a$ is usually 0.01).|Best choice if dead neurons are encountered.|

### Various Optimizers (GD, SGD, Momentum-based, Adagrad, Adam)

Optimization algorithms aim to find the optimal parameters that significantly reduce the error function (cost function $J(\theta)$).

#### Batch Gradient Descent (BGD)

BGD calculates the error for _all_ training examples before updating the model weights once.

- **Upsides:** Computationally efficient (fewer updates), more stable error gradient, stable convergence.
- **Downsides:** Can lead to premature convergence, typically requires the entire training dataset in memory, and training speed can be slow for large datasets.

#### Stochastic Gradient Descent (SGD)

SGD calculates the error and updates the model for _each_ example in the training dataset.

- **Upsides:** Frequent updates provide insight into performance, faster learning possible, and the noisy update process can help the model avoid local minima.
- **Downsides:** Computationally expensive (frequent updates), noisy gradient signal (high variance), making it hard to settle on an error minimum.

#### Gradient Descent with Momentum

This method computes the **exponentially weighted average (EWMA)** of the gradients and uses this value to update weights.

- **Goal:** Damping down oscillations that arise in gradient descent.
- **Benefit:** Damps down the change in step size, useful when the objective function has a large amount of curvature or noisy gradients, and helps the search progress across flat regions.
- **Drawback:** Can overshoot the global minimum or oscillate around it.

#### RMS Prop (Root Mean Square Prop)

RMS Prop calculates an exponentially weighted average of the **squares** of the derivatives ($S_{dW}$).

- **Intuition:** Speeds up learning in directions with small gradients ($W$) and slows down learning (dampens oscillations) in directions with large gradients ($b$).
- **Upsides:** Faster convergence than SGD, robustness to different learning rates, adaptive learning rate.
- **Downsides:** Can sometimes lead to slow convergence, sensitive to the learning rate.

#### Adam (Adaptive moment estimation)

Adam combines the principles of **Gradient Descent with Momentum** and **RMSprop**.

- It computes both a momentum-like update ($V_{dW}$) and an RMSprop-like update ($S_{dW}$).
- **Advantages:** Provides **adaptive learning rates** for each parameter, uses momentum to smooth fluctuations, applies **bias correction** to moment estimates, and is relatively robust across different deep learning architectures.
- **Disadvantages:** Memory intensive (stores moving averages for all parameters), and may converge slower or to flawed solutions in some specific tasks.

---

## Support Vector Machines (SVM)

### Margin and maximization

**Support Vector Machines (SVM)** primarily work as linear classifiers by default. The objective of SVM is to find the **optimal hyperplane**—the line (or plane in 3D, or (d-1)-dimensional hyperplane in d dimensions) that separates the data into classes.

The optimal hyperplane is chosen by maximizing the width of the "street" (the **margin**) that separates the positive examples from the negative examples.

The separating hyperplane (median line) equation is $W^T X + b = 0$, where $W$ is a vector normal to the hyperplane. The two parallel support hyperplanes defining the margin are represented by:

- $W^T X + b = +1$
- $W^T X + b = -1$

The **width of the canal** (margin) is $2 / ||W||$. Maximizing the margin is the goal, which is equivalent to minimizing $||W||$.

### SVM - The primal problem

The problem of finding the optimal hyperplane is an optimization problem. For a linearly separable dataset, the primal objective is formulated as:

**Minimize:**

$$
\frac{1}{2} ||W||^2
$$

**Subject to the constraints:**

$$
y_i (W^T X_i + b) \ge 1 \quad \text{for } i=1 \text{ to } m
$$

 (Where $m$ is the number of training instances).

This is a constrained convex quadratic optimization problem.

### The Lagrangian dual

This constrained optimization problem is typically solved using the **Lagrangian multiplier method** or, more efficiently, through **Lagrange duality**.

The Lagrangian function is introduced to handle constraints:

$$
L(X, \lambda) = f(X) - \lambda g(X)
$$

In the SVM formulation, $\alpha_i$ (Lagrange Multipliers) are introduced for each training instance. Solving the dual problem is preferred because it allows for the use of **kernels** and is generally more efficient than solving the primal problem directly.

### SVM – Solution to the Lagrangian dual (Hard Margin and Soft Margin, Classification ONLY)

#### Hard Margin SVM

The solution to the dual problem requires satisfying the **Karush–Kuhn–Tucker (KKT) Conditions** for inequality constraints. One key KKT condition is **Complementary Slackness** ($\lambda_i g(X_i) = 0$).

This condition implies that for training instances not lying on the margin ("gutter"), the corresponding Lagrange multiplier ($\lambda$) must be zero. Only those instances that lie directly on the boundary hyperplanes ($W^T X + b = \pm 1$) have non-zero multipliers. These crucial instances are called **Support Vectors**. The support vectors define the separating hyperplane.

**Hard Margin SVM** requires that all data points are classified correctly. However, it is highly sensitive to outliers or noise in the training set, often leading to **overfitting**.

#### Soft Margin SVM

**Soft Margin SVM** relaxes the strict requirement of Hard Margin SVM by allowing some points to violate the margin.

This is achieved by introducing **slack variables** ($\xi_i$):

- $\xi_i = 0$: Point is correctly classified and outside the margin.
- $0 < \xi_i < 1$: Point is inside the margin but on the correct side.
- $\xi_i > 1$: Point is misclassified.

The Soft Margin objective function is modified to include a penalty term for these violations:

$$
\text{Minimize: } \frac{1}{2} ||W||^2 + C \sum \xi_i
$$

$C$ is the **Regularization Parameter**, which dictates the trade-off between maximizing the margin and minimizing classification mistakes.

- **Large C:** Focus on avoiding misclassification (smaller margin, closer to Hard SVM).
- **Small C:** Focus on maximizing the margin (more violations allowed, resulting in a softer margin).

### Kernel Functions: Linear, Polynomial (Derivation only for linear function)

**Kernel functions** are used when data is **not linearly separable** in the original input space.

The strategy is to map the original input data ($X$) into a higher-dimensional feature space where the data becomes separable (the **Kernel Trick**).

The **Kernel Trick** is an efficient way to achieve this. Instead of explicitly transforming the data and calculating the dot product in the high-dimensional space (which is computationally expensive, $O(n^2)$), the kernel function accepts vectors in the original lower dimension and returns a scalar that provides the _effect_ of performing the dot product in the higher dimension, often achieving this much faster ($O(n)$ complexity).

#### Linear Kernel

The linear kernel is defined as $K(x, x') = x^T x'$. It is used when the data is already linearly separable or when dealing with a large number of features, such as in text classification.

_(Note: The sources provide the definition and application context of the linear kernel but do not contain a derivation.)_

#### Polynomial Kernel

The polynomial kernel is defined as $K(x, x') = (\gamma x^T x' + c)^d$. Here, $c$ is a constant and $d$ is the degree of the kernel. Increasing the degree ($d$) makes the decision boundary more complex, which increases the tendency toward **overfitting**.

---

## Combining weak learners

**Ensemble Learning** proposes an alternative approach to machine learning. Instead of relying on a single complex and expensive model (a strong learner), it uses multiple simple, computationally inexpensive models known as **weak learners** (e.g., decision stumps or perceptrons).

Although weak learners have low individual predictive power (slightly better than random classification), combining their predictions in some fashion creates a strong ensemble model.

The goal of ensemble methods is to improve stability and predictive power, specifically by reducing the overall **bias** and/or **variance** of the models. Combining observations reduces variance.

Weak learners can be generated by varying:

- The underlying algorithms (e.g., Decision Stump, Perceptron).
- Hyperparameters of the same algorithm.
- **Different subsets of the training data** (resampling—most popular).
- Different features of the training data.

The errors made by these weak learners must ideally be independent and random. Predictions can be combined using simple **majority voting** (mode or mean) or **weighted voting**.

## Improving performance with Gradient Boost

**Boosting** is an ensemble method where models are trained **sequentially**.

The core idea is that a second model is built to focus specifically on accurately predicting the cases where the first model performed poorly. This process is repeated, with each successive model attempting to correct the shortcomings of the combined ensemble of all previous models.

In boosting, weights are associated with each training instance. Misclassified instances receive **more weight**, and correctly classified instances receive less weight. This ensures that the next weak learner focuses greater attention on the instances misclassified by the previous learners.

**Gradient Boost** is an ensemble algorithm that follows this sequential approach, creating and combining multiple models to achieve more accurate predictions.

## Random Forest

**Random Forest** is an ensemble classifier that uses many **decision tree models**. It can be applied to both classification and regression problems.

Random Forest is a type of **bagging** ensemble method. The working of the Random Forest algorithm involves:

1. **Create Bootstrapped Datasets:** Multiple subsets are created from the original dataset by selecting observations **with replacement** (bootstrapping).
2. **Create Decision Trees:** A base model (decision tree) is trained on each bootstrapped sample. For each tree, only a **random subset of attributes** ($R < M$ total attributes) is chosen to determine the best possible split.
3. **Prediction by Voting:** The final prediction is determined by combining the predictions of all the individual trees (majority voting for classification).

A feature of Random Forest is the automatic generation of **Out-of-Bag (OOB) samples**. Since sampling is done with replacement, approximately 37% of the original data is not selected for a sufficiently large bootstrap sample. These OOB samples are not used to train the corresponding model and thus serve as a good test set to evaluate model performance and calculate the OOB error.

**Advantages of Random Forest** include:

- No need for tree pruning.
- Overfitting is generally not a problem.
- Accuracy and variable importance are generated automatically.
- Not very sensitive to outliers.
- Good overall performance and ease of parameter setting
