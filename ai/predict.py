
import tensorflow as tf
import numpy as np

interpreter = tf.lite.Interpreter(
    model_path=
    "model/comfort_model.tflite"
)

interpreter.allocate_tensors()

input_details = \
    interpreter.get_input_details()

output_details = \
    interpreter.get_output_details()

sample = np.array(
    [[28,60,300,1]],
    dtype=np.float32
)

interpreter.set_tensor(
    input_details[0]['index'],
    sample
)

interpreter.invoke()

prediction = interpreter.get_tensor(
    output_details[0]['index']
)

print(
    "Predicted Comfort Score:",
    prediction[0][0]
)
