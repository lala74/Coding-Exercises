#!/bin/bash
#################################################
# README
#################################################

#################################################
# Constant
languages=(
    "C"
    "C++"
    "Python"
)

websites=(
    "Kattis"
    "Divers"
)

red="\e[41m"
bold="\e[1m"
reset="\e[0m"

formatFolderName="DefaultFormat"
readmeFormatFileName="README-format.md"
readmeFileName="README.md"

#################################################
# Function
function print_usage() {
    websiteFull="|"
    for website in "${websites[@]}"; do
        websiteFull+="$website|"
    done
    languageFull="|"
    for language in "${languages[@]}"; do
        languageFull+="$language|"
    done

    echo -e "${red}${bold}${1}${reset}" # Print error msg if there is any
    echo "Usage:                                                     #"
    echo "      create_folder ${websiteFull} <problemName> ${languageFull}      #"
    exit 1
}

function is_value_in_set() {
    local value="${1}"
    shift
    local set=("$@")
    for element in "${set[@]}"; do
        if [ "${value}" == "${element}" ]; then
            return 0
        fi
    done
    return -1
}

function create_folder() {
    if [ $# -ne 3 ]; then
        print_usage
    fi
    website=${1}
    problemName=${2}
    language=${3}

    is_value_in_set "${website}" "${websites[@]}"
    [ $? -eq 0 ] || print_usage "Website invalid"
    is_value_in_set "${language}" "${languages[@]}"
    [ $? -eq 0 ] || print_usage "Language invalid"

    # Get file name extension
    languageFileNameExtension=""
    case ${language} in
    "C")
        languageFileNameExtension=".c"
        ;;
    "C++")
        languageFileNameExtension=".cpp"
        ;;
    "Python")
        languageFileNameExtension=".py"
        ;;
    esac

    # Create directory tree
    mkdir -p ${website}/${problemName}/${language}
    # Copy readme
    cp ${formatFolderName}/${readmeFormatFileName} ${website}/${problemName}/${readmeFileName}
    # Copy main
    cp ${formatFolderName}/main${languageFileNameExtension} ${website}/${problemName}/${language}
}

#################################################
# Main
if [ "${1}" == "create_folder" ]; then
    create_folder ${2} ${3} ${4}
else
    print_usage
fi
