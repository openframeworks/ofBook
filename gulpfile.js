var gulp        = require('gulp');
var browserSync = require('browser-sync').create();
var sass        = require('gulp-sass');

// Static Server + watching scss/html files
gulp.task('serve', ['sass'], function() {

    browserSync.init({
        server: "./output/webBook"
    });

    gulp.watch("static/style/*.scss", ['sass']);
    //gulp.watch("output/webBook/chapter/*.html").on('change', browserSync.reload);
    gulp.watch("output/webBook/**").on('change', browserSync.reload);
});

// Compile sass into CSS & auto-inject into browsers
gulp.task('sass', function() {
    return gulp.src("static/style/style.scss")
        .pipe(sass())
        .pipe(gulp.dest("output/webBook/style/"))
        .pipe(browserSync.stream());
});

gulp.task('default', ['serve']);