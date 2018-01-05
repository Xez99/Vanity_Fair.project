#encoding "utf8"    
#GRAMMAR_ROOT Relation


RelationWord -> 'друг' | 'сын' | 'дочь' | 'доченька' | 'отец' | 'папа' | 'мать' | 'мама'  | 'муж' | 'жена' | 'женат' | 'подруга' | 'супруг' | 'супруга' | 'сестра' |'сестрица'|'братишка' | 'брат' | 'тетя' | 'тётя' | 'дядя'; 

Person -> Word<kwtype=person, h-reg1, gc-agr[1]> Word<h-reg1, gc-agr[1]>;

Trash -> Word | LBracket | RBracket | Comma | Colon;

Relation -> Person interp(Relations.MainName) Trash* RelationWord interp(Relations.RelationName) Trash* Person interp(Relations.SecondName);
Relation -> Person Trash* Word<kwtype=person, h-reg1> interp(Relations.MainName) Comma Trash* RelationWord interp(Relations.RelationName) Trash* Person interp(Relations.SecondName);
Relation -> RelationWord interp(Relations.RelationName) Trash* Person interp(Relations.MainName) Trash* Person interp (Relations.SecondName);
Relation -> RelationWord Trash* Person interp(Relations.MainName) Trash* RelationWord interp(Relations.RelationName) Trash* Person interp (Relations.SecondName);
Relation -> Person interp(Relations.MainName) Trash* 'его' RelationWord interp(Relations.RelationName) Trash* Person interp(Relations.SecondName);
Relation -> Person interp(Relations.MainName) Trash* RelationWord interp(Relations.RelationName) Trash* Word<kwtype=person, h-reg1> interp(Relations.SecondName);