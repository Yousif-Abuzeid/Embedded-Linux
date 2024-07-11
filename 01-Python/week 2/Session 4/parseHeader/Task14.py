import re
import openpyxl

class PrototypeExtractor:
    def __init__(self, header_file, excel_file):
        """
        Initialize the PrototypeExtractor with the given header file and excel file paths.

        :param header_file: Path to the C header file containing function prototypes.
        :param excel_file: Path to the Excel file where prototypes will be written.
        """
        self.header_file = header_file
        self.excel_file = excel_file

    def extract_prototypes(self):
        """
        Extract function prototypes from the header file using a regular expression.

        :return: A list of extracted function prototypes.
        """
        # Regular expression to match function prototypes
        prototype_pattern = re.compile(r'\b\w+\s+\w+\(.*?\);')
        prototypes = []

        # Read the header file line by line
        with open(self.header_file, 'r') as file:
            for line in file:
                # Search for a match in the current line
                match = prototype_pattern.search(line)
                if match:
                    # Add the matched prototype to the list
                    prototypes.append(match.group())
        return prototypes

    def write_to_excel(self, prototypes):
        """
        Write the extracted prototypes to an Excel file with unique IDs.

        :param prototypes: A list of function prototypes to be written to the Excel file.
        """
        # Create a new Excel workbook and select the active sheet
        workbook = openpyxl.Workbook()
        sheet = workbook.active
        sheet.title = "Prototypes"

        # Write the header row
        sheet.append(["Function Prototype", "Unique ID"])

        # Write each prototype with a unique ID to the Excel sheet
        for idx, prototype in enumerate(prototypes, start=1):
            unique_id = f"IDX{idx:03}"
            sheet.append([prototype, unique_id])

        # Save the workbook to the specified file
        workbook.save(self.excel_file)
        print(f"Data written to {self.excel_file}")

def main():
    """
    Main function to test the PrototypeExtractor class.
    """
    # Specify the paths to the input header file and output Excel file
    header_file = '/home/youssef-abuzeid/Embedded Linux/Embedded-Linux/01-Python/week 2/Session 4/parseHeader/uart.h'
    excel_file = 'functions.xlsx'

    # Create an instance of PrototypeExtractor
    extractor = PrototypeExtractor(header_file, excel_file)

    # Extract prototypes from the header file
    prototypes = extractor.extract_prototypes()

    # Write the extracted prototypes to the Excel file
    extractor.write_to_excel(prototypes)

if __name__ == "__main__":
    main()
