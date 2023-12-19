/*
* 门诊科室：（各小组可根据需要部分选用门诊科室）
    1）	内科：呼吸内科","消化内科","神经内科","心血管内科","肾内科","血液内科","免疫科","内分泌科。
    2）	外科：普通外科","神经外科","心胸外科","泌尿外科","心血管外科","乳腺外科","肝胆外科","肛肠外科","烧伤科","骨外科。
    3）	儿科：小儿内科","小儿外科","新生儿科","儿童营养保健科。
    4）	五官科：耳鼻喉科","眼科","口腔科。
 */

#ifndef DEPARTMENTO_H
#define DEPARTMENTO_H

extern const char mainDepartmentC[][50];
extern const char IMDC[][50];
extern const char SDC[][50];
extern const char PDC[][50];
extern const char EDC[][15];


// 大类科室

enum mainDepartment { Inner, Surgery, PediatricM, ENT };


// 内科

enum IMD {
    Respiratory,
    Gastroenterology,
    Neurology,
    Cardiovascular,
    Nephrology,
    Hematopathology,
    Immunology,
    Endocrinology
};


// 外科

enum SD {
    General,
    Neurosurgery,
    cardiothoracic,
    Urology,
    CardiovascularS,
    Breast,
    Hepatobiliary,
    Anorectal,
    Burn,
    Bone
};


// 儿科

enum PD { Internal, Pediatric, Neonatology, CNAHC };


// 五官科

enum ED { Otolaryngology, Ophthalmology, Stomatology };


typedef struct department {
    enum mainDepartment main;

    union {
        enum IMD imd;
        enum SD sd;
        enum PD pd;
        enum ED ed;
    } sub;
} Department;


#endif //DEPARTMENTO_H
