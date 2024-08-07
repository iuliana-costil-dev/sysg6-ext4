# Exploring ext4 File System

## Project Overview
This repository contains C codes and documentation to explore the ext4 file system. The project demonstrates how to interact with and analyze ext4 file systems, including reading superblocks and other metadata.
   
## Directory Structure

### 1. Books
Contains resources and references used during the research.

### 2. Codes
Contains various C codes to explore file systems.

### 3. Latex
Contains LaTeX files and outputs related to the ext4 file system documentation.
- `ext4.pdf`: Comprehensive documentation on the ext4 file system.

### 4. Images
Contains various image files used for visual representation in the documentation.

### 5. Outils
Contains various LaTeX templates, source files, and example documents as well as tools and additional resources.

## Getting Started
To explore the ext4 file system and run the provided C codes, follow these steps:

1. **Prepare a Separate USB Drive**:
   Ensure you have a separate USB drive or another storage device dedicated to experimenting with the ext4 file system. This precaution is crucial to avoid any accidental data loss on your primary device.

2. **Create an ext4 File System**:
   Follow the instructions in the `ext4.pdf` documentation to create an ext4 file system on the USB drive. Here is a brief outline of the steps:
   
   - **Format the USB Drive**:
     ```sh
     sudo mkfs.ext4 /dev/sdX
     ```
     Replace `/dev/sdX` with the appropriate device identifier for your USB drive.
   
   - **Mount the USB Drive**:
     ```sh
     sudo mount /dev/sdX /mnt
     ```
     This command mounts the USB drive to the `/mnt` directory. You can choose a different mount point if desired.
   
   - **Verify the File System**:
     Use tools like `dumpe2fs` to verify the ext4 file system:
     ```sh
     sudo dumpe2fs /dev/sdX
     ```

3. **Compile the C Codes**:
   Navigate to the `Codes` directory and compile the C files using the provided `Makefile`. Simply run:
   ```sh
   make
   ```
	This will compile all the necessary programs as specified in the Makefile.

4. **Run the Demos**:
    Once the programs are compiled, you can use the provided Demo script to analyze or manipulate the ext4 file system on your USB drive. The Demo script provides a guided demonstration of the tools.
    Run the Demo Script:

    ```sh
    ./Demo
	```
    Follow the prompts in the script to see the results of various commands. The script will guide you through inserting your USB drive, displaying information about it, and running the compiled LectSuperBlock program to read the superblock.

5. **Review the Documentation**:
    Open Latex/ext4.pdf to review the detailed documentation on the ext4 file system. This document includes explanations of the provided C codes and their outputs, offering in-depth information on:
    -  Structure of the ext4 file system
    -  Key features and improvements of ext4
    -  Sample code and its functionality

By following these steps, you can safely experiment with the ext4 file system and understand its internal workings using the provided codes and documentation.

## Conclusion
This project was created as part of the curriculum at Haute École Bruxelles Brabant - École Supérieure d'Informatique. It serves as an educational tool to explore and understand the ext4 file system through hands-on experience with formatted storage devices and custom C programs. By following the steps outlined in this guide, you can gain practical insights into the structure and functionalities of the ext4 file system, enhancing your knowledge and skills in filesystem management and development.
