path = '~/Dropbox/comcast/green_lantern_symbol/';
filename = 'img28.jpg';
img = imread(fullfile(path,filename));
bg = imcrop(img);
gray=rgb2gray(bg);
imshow(gray);
gray = reshape(gray,1,numel(gray));
bg_mean = mean(gray);
bg_min = min(gray);
bg_max = max(gray);

fg = imcrop(img);
gray=rgb2gray(fg);
gray = reshape(gray,1,numel(gray));
fg_mean = mean(gray);
fg_min = min(gray);
fg_max = max(gray);

bg_attr = [bg_mean bg_min bg_max]
fg_attr = [fg_mean fg_min fg_max]
