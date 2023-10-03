function [convertedNumber] = conversione(number, baseBeta)
% conversione numero da base 10 a base beta qualsiasi
% INPUT: numero da convertire, base beta qualsiasi
% OUTPUT: numero convertito in base beta

convertedNumber = "";

while number > 0
    rest = rem(number, baseBeta);
    number = fix(number/baseBeta);
    convertedNumber = strcat(num2str(rest), convertedNumber);
end

end
