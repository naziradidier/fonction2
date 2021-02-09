NIntegrale(f,x,a,b,n) =
{
  // Vérifie les paramètres
  Si (EstType(x,"VAR")==FAUX) Erreur ("x doit être une variable !");
  a = Approx(a);
  Si (EstType(a,"REAL")==FAUX) Erreur ("a doit être un nombre réel !");
  b = Approx(b);
  Si (EstType(b,"REAL")==FAUX) Erreur ("b doit être un nombre réel !");
 
  // Passe en calcul approché
  Config ("EXACT",FAUX);
 
  // Calcule la largeur d'un sous-intervalle
  k = (b-a)/n;  
 
  // En utilisant la éthode des trapèzes (du point médian)
  s = (Eval(f,x,a)+Eval(f,x,b))/2;
  Pour (i=1, i<n, i++)
  {
    a += k;
    s += Eval(f,x,a);
  };
 
/*
  // En utilisant la méthode des rectangles (pris à gauche)
  s = 0;
  Pour (i=0, i<=n-1, i++)
  {
    s += Eval(f,x,a);
    a += k;
  };
*/
 
  Retourne (k*s);
};