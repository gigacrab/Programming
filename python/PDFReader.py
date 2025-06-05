import os
import PyPDF2
import pandas as pd

def list_files_in_directory(directory_path):
    file_list = os.listdir(directory_path)
    return file_list

def extract_text_from_first_page(pdf_path):
    with open(pdf_path, 'rb') as file:
        reader = PyPDF2.PdfReader(file)
        first_page = reader.pages[0]
        text = first_page.extract_text()
        return text

def rename_pdf_based_on_text(pdf_path, new_name):
    directory, old_name = os.path.split(pdf_path)
    new_path = os.path.join(directory, f"{new_name}.pdf")
    os.rename(pdf_path, new_path)
    print(f"Renamed '{old_name}' to '{new_name}.pdf'")

def main():
    master_list = {}
    all_name = []
    all_grades = []
    directory_path = "/home/littlecrabby/Documents/SPM-Results/" 
    all_pdf_paths = list_files_in_directory(directory_path)

    ori_pdf_count = len(all_pdf_paths)

    for pdf_path in all_pdf_paths:
        text = extract_text_from_first_page("/home/littlecrabby/Documents/SPM-Results/"+pdf_path)

        info = text.split('\n') 

        n = 0
        grades = []
        for i in info:
            if (n > 56):
                if i[0] in ["1", "2", "3", "4", "5", "6", "7", "8", "9", "0"]:
                    grade = i[5]
                    if(i[6] in ["-", "+"]):
                        grade += i[6]
                    else:
                        grade += ","
                    if grade[0] not in ["(", "P"]:
                        grades.append(grade)
            n += 1
        grades.sort()
        uniq = []
        for g in grades:
            if (g not in uniq):
                uniq.append(g)
        grades_out = ""

        a_count = 0

        for i in uniq:
            count = grades.count(i)
            if i in ["A+", "A-", "A,"]:
                a_count += count
            grades_out += str(count) + i + " "

        grades_out = grades_out.replace(",", "")

        new_name = str(a_count) + "As " + info[52].strip() + " " + grades_out.strip()
        new_name = new_name.replace("/", "")

        rename_pdf_based_on_text("/home/littlecrabby/Documents/SPM-Results/"+pdf_path, new_name)

        master_list[info[52].strip()] = grades_out.strip()
        all_name.append(info[52].strip())
        all_grades.append(grades_out.strip())
        print(f"Progress: {all_pdf_paths.index(pdf_path) + 1}/{ori_pdf_count}")

    results = pd.DataFrame({'Name':all_name,'Grades':all_grades})
    results.to_csv('SPM-Results-List.csv',index=False)

main()
