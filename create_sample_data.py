import numpy as np

def main():
    array0 = np.array([0, 1, 2, 3, 4, 5], dtype=np.float32)
    array1 = np.array([[1, 2, 3], [4, 5, 6]], dtype=np.float32)

    np.savez("sample_data.npz", array0, array1)
    np.savez_compressed("sample_data_compressed.npz", array0, array1)

if __name__ == "__main__":
    main()
