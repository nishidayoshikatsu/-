import mglearn
import matplotlib.pyplot as plt
from sklearn.datasets import load_breast_cancer
from sklearn.datasets import load_boston
from sklearn.model_selection import train_test_split
from sklearn.neighbors import KNeighborsClassifier
from sklearn.neighbors import KNeighborsRegressor
import numpy as np

data = "wave"

if data == "forge":
    # データセットの生成
    X, y = mglearn.datasets.make_forge()
    # データセットをプロット
    plt.figure(0)
    mglearn.discrete_scatter(X[:, 0], X[:, 1], y)
    plt.legend(["Class 0", "Class 1"], loc=4)
    plt.xlabel("First feature")
    plt.ylabel("Second feature")
    plt.show()
    print("X.shape: {}".format(X.shape))

    X_train, X_test, y_train, y_test = train_test_split(X, y, random_state=0)       # データの分割
    #clf = KNeighborsClassifier(n_neighbors=1)
    #clf.fit(X_train, y_train)
    #print("Test set predictions: {}".format(clf.predict(X_test)))
    #print("Test set accuracy: {:.2f}".format(clf.score(X_test, y_test)))

    plt.figure(1)
    fig, axes = plt.subplots(1, 3, figsize=(10, 3))
    for n_neighbors, ax in zip([1, 3, 9], axes):
        # the fit method returns the object self, so we can instantiate
        # and fit in one line
        clf = KNeighborsClassifier(n_neighbors=n_neighbors).fit(X, y)
        mglearn.plots.plot_2d_separator(clf, X, fill=True, eps=0.5, ax=ax, alpha=.4)
        mglearn.discrete_scatter(X[:, 0], X[:, 1], y, ax=ax)
        ax.set_title("{} neighbor(s)".format(n_neighbors))
        ax.set_xlabel("feature 0")
        ax.set_ylabel("feature 1")
    axes[0].legend(loc=3)
    plt.show()
elif data == "wave":
    X, y = mglearn.datasets.make_wave(n_samples=40)
    plt.figure(0)
    plt.plot(X, y, 'o')
    plt.ylim(-3, 3)
    plt.xlabel("Feature")
    plt.ylabel("Target")
    plt.show()

    # split the wave dataset into a training and a test set
    X_train, X_test, y_train, y_test = train_test_split(X, y, random_state=0)

    # instantiate the model and set the number of neighbors to consider to 3
    reg = KNeighborsRegressor(n_neighbors=3)
    # fit the model using the training data and training targets
    reg.fit(X_train, y_train)
    print("Test set predictions:\n", reg.predict(X_test))
    print("Test set R^2: {:.2f}".format(reg.score(X_test, y_test)))

    plt.figure(1)
    fig, axes = plt.subplots(1, 3, figsize=(15, 4))
    # create 1,000 data points, evenly spaced between -3 and 3
    line = np.linspace(-3, 3, 1000).reshape(-1, 1)
    for n_neighbors, ax in zip([1, 3, 9], axes):
        # make predictions using 1, 3, or 9 neighbors
        reg = KNeighborsRegressor(n_neighbors=n_neighbors)
        reg.fit(X_train, y_train)
        ax.plot(line, reg.predict(line))
        ax.plot(X_train, y_train, '^', c=mglearn.cm2(0), markersize=8)
        ax.plot(X_test, y_test, 'v', c=mglearn.cm2(1), markersize=8)

        ax.set_title(
            "{} neighbor(s)\n train score: {:.2f} test score: {:.2f}".format(
                n_neighbors, reg.score(X_train, y_train),
                reg.score(X_test, y_test)))
        ax.set_xlabel("Feature")
        ax.set_ylabel("Target")
    axes[0].legend(["Model predictions", "Training data/target",
                    "Test data/target"], loc="best")
    plt.show()
elif data == "cancer":
    cancer = load_breast_cancer()
    print("cancer.keys():\n{}".format(cancer.keys()))
    print("Shape of cancer data: {}".format(cancer.data.shape))
    print("Sample counts per class:\n{}".format({n: v for n, v in zip(cancer.target_names, np.bincount(cancer.target))}))
    print("Feature names:\n{}".format(cancer.feature_names))
    X_train, X_test, y_train, y_test = train_test_split(cancer.data, cancer.target, stratify=cancer.target, random_state=66)
    training_accuracy = []
    test_accuracy = []
    # try n_neighbors from 1 to 10
    neighbors_settings = range(1, 11)

    for n_neighbors in neighbors_settings:
        # build the model
        clf = KNeighborsClassifier(n_neighbors=n_neighbors)
        clf.fit(X_train, y_train)
        # record training set accuracy
        training_accuracy.append(clf.score(X_train, y_train))
        # record generalization accuracy
        test_accuracy.append(clf.score(X_test, y_test))

    plt.plot(neighbors_settings, training_accuracy, label="training accuracy")
    plt.plot(neighbors_settings, test_accuracy, label="test accuracy")
    plt.ylabel("Accuracy")
    plt.xlabel("n_neighbors")
    plt.legend()
    plt.show()
elif data == "boston_load":
    boston = load_boston()
    print("Data shape: {}".format(boston.data.shape))
    X, y = mglearn.datasets.load_extended_boston()
    print("X.shape: {}".format(X.shape))

