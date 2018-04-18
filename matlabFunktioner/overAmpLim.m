function output = overAmpLim(peaks, min, ampLim)

  boolPKS = peaks >= -min + abs(peaks+min) ./ 2 + ampLim;
  
  output = sum(boolPKS) == length(boolPKS);
end