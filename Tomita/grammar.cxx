#encoding "utf8"    
#GRAMMAR_ROOT Relation


RelationWord -> 'друг' | 'сын' | 'дочь' | 'доченька' | 'отец' | 'папа' | 'мать' | 'мама'  | 'муж' | 'жена' | 'женат' | 'подруга' | 'супруг' | 'супруга' | 'сестра' |'сестрица'|'братишка' | 'брат' | 'тетя' | 'тётя' | 'дядя'; 

Person -> Word<kwtype=person, h-reg1, gc-agr[1]> Word<h-reg1, gc-agr[1]>;

Trash -> Word | LBracket | RBracket | Comma | Colon;

Relation -> Person interp(Relative.MainName) Trash* RelationWord interp(Relative.RelationName) Trash* Person interp(Relative.SecondName);
Relation -> Person Trash* Person interp(Relative.MainName) Comma Trash* RelationWord interp(Relative.RelationName) Trash* Person interp(Relative.SecondName);
Relation -> RelationWord interp(Relative.RelationName) Trash* Person interp(Relative.MainName) Trash* Person interp (Relative.SecondName);
Relation -> RelationWord Trash* Person interp(Relative.MainName) Trash* RelationWord interp(Relative.RelationName) Trash* Person interp (Relative.SecondName);
Relation -> Person interp(Relative.MainName) Trash* 'его' RelationWord interp(Relative.RelationName) Trash* Person interp(Relative.SecondName);
Relation -> Person interp(Relative.MainName) Trash* RelationWord interp(Relative.RelationName) Trash* 'Миссис'<gc-agr[1]> Word<h-reg1, gc-agr[1]> interp(Relative.SecondName);