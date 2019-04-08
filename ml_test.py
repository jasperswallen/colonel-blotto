#Load libraries
import pandas
from pandas.plotting import scatter_matrix
import matplotlib.pyplot as plt
from sklearn import model_selection
from sklearn.metrics import classification_report
from sklearn.metrics import confusion_matrix
from sklearn.metrics import accuracy_score
from sklearn.linear_model import LogisticRegression
from sklearn.tree import DecisionTreeClassifier
from sklearn.neighbors import KNeighborsClassifier
from sklearn.discriminant_analysis import LinearDiscriminantAnalysis
from sklearn.naive_bayes import GaussianNB
from sklearn.svm import SVC

#Load dataset
url = "dataset.csv"
names = ['1','2','3','4','5','6','7','8','9','10','Sum']
dataset = pandas.read_csv(url, names=names)

#shape
print(dataset.shape)

#head
print(dataset.head(20))

#descriptions
print(dataset.describe())

#sum description
print(dataset.groupby('Sum').size())

### Doesn't work, since too much data
#box and whisker plots
#dataset.plot(kind='box', subplots=True, layout=(2,2), sharex=False, sharey=False)
#plt.show()

#histogram
dataset.hist()
plt.show()

#scatter plot matrix
scatter_matrix(dataset)
plt.show()