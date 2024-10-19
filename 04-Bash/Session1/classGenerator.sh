#!/usr/bin/bash

# This script will generate a class file with the given name

name="Youssef Abuzeid"
read -p "Enter the namespace name: " namespaceName
read -p "Enter the class name: " className

if [ -z "$className" ]; then
    echo "Class name cannot be empty"
    exit 1
fi


if [ -f "${className}.hpp" ]; then
    echo "Class file already exists"
    exit 1
fi

echo "
#pragma once

/***********************************************************************/
//
// 
//                  Copyright ${name}
//
//
/***********************************************************************/

/**
 * @author $name
 * @file ${className}.hpp
 * @date $(date)
 * @brief This file contains the definition of the ${className} class
 */

namespace ${namespaceName} {
    class ${className} {
    public:
        ${className}();
        ~${className}();
    private:
    };
}

" > "${className}.hpp"

echo "
#include \"${className}.hpp\"


/***********************************************************************/
//
// 
//                  Copyright ${name}
//
//
/***********************************************************************/

/**
 * @author $name
 * @file ${className}.hpp
 * @date $(date)
 * @brief This file contains the implementation of the ${className} class
 */

namespace ${namespaceName} {
    ${className}::${className}() {
    }

    ${className}::~${className}() {
    }
}

" > "${className}.cpp"

