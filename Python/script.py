from ultralytics import YOLO
import cv2

# Load pre-trained YOLOv8 model (custom model trained for scrap types recommended)
model = YOLO("yolov8n.pt")  # Replace with your custom model file

# Define possible scrap types for better interpretation
scrap_types = {
    0: "Metal",
    1: "Plastic",
    2: "Paper",
    3: "Glass",
    4: "Wood",
    5: "Electronic Waste",
    6: "Organic Waste",
    7: "Textiles",
    # Add more classes as per your model
}

def classify_scrap(image_path):
    """
    Classify scrap types in an image using YOLOv8.
    :param image_path: Path to the input image.
    """
    # Load the image
    image = cv2.imread(image_path)
    if image is None:
        print("Image not found or cannot be read!")
        return

    # Perform object detection
    results = model(image)

    # Annotate the image with results
    annotated_image = results[0].plot()  # Annotated image with bounding boxes
    detected_scrap = []  # Store the list of detected scrap types

    for box in results[0].boxes:
        cls = int(box.cls)  # Class ID of the detected object
        class_name = scrap_types.get(cls, "Unknown")  # Get class name or default to "Unknown"
        detected_scrap.append(class_name)  # Append detected class name to list
        x1, y1, x2, y2 = map(int, box.xyxy[0])  # Bounding box coordinates

        # Annotate bounding boxes with class name
        cv2.putText(annotated_image, class_name, (x1, y1 - 10),
                    cv2.FONT_HERSHEY_SIMPLEX, 0.5, (0, 255, 0), 2)
        cv2.rectangle(annotated_image, (x1, y1), (x2, y2), (0, 255, 0), 2)

    # Display the annotated image
    cv2.imshow("Scrap Classification", annotated_image)
    cv2.waitKey(0)  # Wait for a key press to close the window
    cv2.destroyAllWindows()

    # Print the detected scrap types
    print("Detected Scrap Types:")
    for scrap in set(detected_scrap):
        print(f"- {scrap}")


# Path to the input image
image_path = "scrap_image.jpg"  # Replace with your image path

# Classify scrap in the image
classify_scrap(image_path)