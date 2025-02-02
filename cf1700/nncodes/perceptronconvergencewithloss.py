from sklearn.datasets import make_classification
import numpy as np
X,y = make_classification(n_smaples=100,n_features=2,n_informative=1,n_redudant=0,n_classes=2,n_clusters_per_class=1,random_state=41,hypercube=False,class_sep=10)

import matplotlib.pyplot as plt

plt.figure(figsize=(10,6))
plt.scatter(x[:,0],x[:1],c=y,cmap='winter',s=100)

def perceptron(x,y):
    x=np.insert(x,0,1,axis=1)
    weights=np.ones(x.shape[1])
    lr=0.1

