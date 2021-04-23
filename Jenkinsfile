pipeline {
    agent any
    stages {
        stage('Build') {
            steps {
                sh 'echo "Hello World"'
                sh '''
                    echo "Multiline shell steps works too"
                    ls -lah
                '''
                sh './build_all.sh'
            }
        }
    }
    post {
        always {
            echo 'One way or another, I have finished'
        }
        success {
            echo 'I succeeeded!'
            mail to: 'fusichang@126.com',
            subject: "Pipeline succeeeded!",
            body: "I succeeeded!"
        }
        unstable {
            echo 'I am unstable :/'
        }
        failure {
            mail to: 'fusichang@126.com',
            subject: "Pipeline wrong!",
            body: "Something is wrong!"
        }
        changed {
            echo 'Things were different before...'
        }
    }
}