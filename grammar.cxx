#encoding "utf8"    
#GRAMMAR_ROOT Relation


ReletiveW -> 'друг' | 'сын' | 'дочь' | 'доченька' | 'отец' | 'папа' | 'мать' | 'мама'  | 'муж' | 'жена' | 'женат' | 'подруга' | 'супруг' | 'супруга' | 'сестра' |'сестрица'|'братишка' | 'брат' | 'тетя' | 'тётя' | 'дядя'; 

Person -> Word<kwtype=person, h-reg1, gc-agr[1]> Word<h-reg1, gc-agr[1]>;

Trash -> Word | LBracket | RBracket | Comma | Colon;

Relation -> Person interp(Relations.MainName) Trash* ReletiveW interp(Relations.RelationName) Trash* Person interp(Relations.SecondName);
Relation -> Person Trash* Word<kwtype=person, h-reg1> interp(Relations.MainName) Comma Trash* ReletiveW interp(Relations.RelationName) Trash* Person interp(Relations.SecondName);
Relation -> ReletiveW interp(Relations.RelationName) Trash* Person interp(Relations.MainName) Trash* Person interp (Relations.SecondName);
Relation -> ReletiveW Trash* Person interp(Relations.MainName) Trash* ReletiveW interp(Relations.RelationName) Trash* Person interp (Relations.SecondName);
Relation -> Person interp(Relations.MainName) Trash* 'его' ReletiveW interp(Relations.RelationName) Trash* Person interp(Relations.SecondName);
Relation -> Person interp(Relations.MainName) Trash* ReletiveW interp(Relations.RelationName) Trash* Word<kwtype=person, h-reg1> interp(Relations.SecondName);