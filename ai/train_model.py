import pandas as pd
import tensorflow as tf

from sklearn.model_selection import train_test_split

data = pd.read_csv(
    "comfort_dataset.csv"
)

X = data[
    [
        "temperature",
        "humidity",
        "light",
        "occupied"
    ]
]

y = data[
    "comfort_score"
]

X_train, X_test, y_train, y_test = \
    train_test_split(
        X,
        y,
        test_size=0.2,
        random_state=42
    )

model = tf.keras.Sequential([
    tf.keras.layers.Dense(
        16,
        activation='relu',
        input_shape=(4,)
    ),

    tf.keras.layers.Dense(
        8,
        activation='relu'
    ),

    tf.keras.layers.Dense(
        1
    )
])

model.compile(
    optimizer='adam',
    loss='mse',
    metrics=['mae']
)

model.fit(
    X_train,
    y_train,
    epochs=100,
    verbose=1
)

model.save(
    "model/comfort_model.h5"
)

print(
    "Model training complete."
)
