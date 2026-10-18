#A. Write a Python program to read the sales data from a CSV file (sample.csv) and plot the region-wise total sales in bar graph and pie chart in single figure.
#Source Code:
import pandas as pd
import matplotlib.pyplot as plt

df = pd.read_csv("sample.csv")
sales = df.groupby("Region")["Sales"].sum()

plt.figure(figsize=(12, 5))

plt.subplot(1, 2, 1)
sales.plot(kind="bar", title="Region-wise Total Sales")
plt.xlabel("Region")
plt.ylabel("Total Sales")

plt.subplot(1, 2, 2)
sales.plot(kind="pie", autopct="%1.1f%%", title="Region-wise Sales Distribution")
plt.ylabel("")

plt.tight_layout()
plt.show()
